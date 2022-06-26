cmake_minimum_required(VERSION 3.23.0)
project(kahip LANGUAGES CXX)

find_package(pybind11 REQUIRED)
pybind11_add_module(kahip_python_binding ${FREEBSD_WRKSRC}/misc/pymodule/kahip.cpp)
target_link_libraries(kahip_python_binding PUBLIC kahip)
set_target_properties(kahip_python_binding PROPERTIES OUTPUT_NAME "kahip")
