//序列化：json数据对象=》json字符串      json js; string sendBuf = js.dump();
//反序列化：json字符串=》json数据对象    json jsBuf = json::parse(string sendBuf);
#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <vector>
#include <string>

std::string func01()
{
    json js;
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    js["vec01"] = vec;
    std::string sendBuf = js.dump();
    return sendBuf;
}

int main()
{
    std::string recvBuf = func01();
    json js = json::parse(recvBuf);
    std::vector<int> vec01 = js["vec01"];
    for(int &v : vec01){
        std::cout << v << " ";
    }
    std::cout<<std::endl;
    return 0;
}