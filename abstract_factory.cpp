//工厂模式-抽象工厂模式

//特点：抽象工厂模式提供创建一系列相关或相互依赖对象的接口，而无需指定它们具体的类。
//当存在多个产品系列，而客户端只使用一个系列的产品时，可以考虑使用抽象工厂模式。

//缺点：当增加一个新系列的产品时，不仅需要现实具体的产品类，还需要增加一个新的创建接口，扩展相对困难。​

/*
* 在一个工厂里聚合多个同类产品。
* 以下代码以白色衣服和黑色衣服为例，白色衣服为一个产品系列，黑色衣服为一个产品系列。白色上衣搭配白色裤子, 黑色上衣搭配黑色裤字。每个系列的衣服由一个对应的工厂创建，这样一个工厂创建的衣服能保证衣服为同一个系列。
*/

#include <iostream>

//抽象上衣类
class Coat
{
public:
    virtual void color() = 0;
};

//黑色上衣类
class BlackCoat : public Coat
{
public:
    void color(){
        std::cout << "BlackCoat" << std::endl;
    }
};

//白色上衣类
class WhiteCoat : public Coat
{
public:
    void color() {
        std::cout << "WhiteCoat" << std::endl;
    }
};

//抽象裤子类
class Pants
{
public:
    virtual void color() = 0;
};

//黑色裤子类
class BlackPants : public Pants
{
public:
    void color() {
        std::cout << "BlackPants" << std::endl;
    }
};

//白色裤子类
class WhitePants : public Pants
{
public:
    void color() {
        std::cout << "WhitePants" << std::endl;
    }
};

//抽象工厂类，提供衣服创建接口
class Factory
{
public:
    //上衣创建接口，返回抽象上衣类
    virtual std::unique_ptr<Coat> createCoat() = 0;
    //裤子创建接口，返回抽象裤子类
    virtual std::unique_ptr<Pants> createPants() = 0;
};

//创建白色衣服的工厂类，具体实现创建白色上衣和白色裤子的接口
class WhiteFactory : public Factory
{
public:
    std::unique_ptr<Coat> createCoat(){
        return std::make_unique<WhiteCoat> ();
    }
    std::unique_ptr<Pants> createPants() {
        return std::make_unique<WhitePants>();
    }
};

//创建黑色衣服的工厂类，具体实现创建黑色上衣和白色裤子的接口
class BlackFactory : public Factory
{
public:
    std::unique_ptr<Coat> createCoat() {
        return std::make_unique<BlackCoat>();
    }
    std::unique_ptr<Pants> createPants() {
        return std::make_unique<BlackPants>();
    }
};

int main() {
    std::unique_ptr<Factory> factory1 = std::make_unique<WhiteFactory>();
    factory1->createCoat()->color();
    factory1->createPants()->color();
    std::cout << "白色系列创建成功！" << std::endl;

    std::unique_ptr<Factory> factory2 = std::make_unique<BlackFactory>();
    factory2->createCoat()->color();
    factory2->createPants()->color();
    std::cout << "黑色系列创建成功！" << std::endl;
}