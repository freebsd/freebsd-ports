--- cmake/OptimizeForArchitecture.cmake.orig	2022-12-12 19:13:40 UTC
+++ cmake/OptimizeForArchitecture.cmake
@@ -116,7 +116,7 @@ macro(OFA_AutodetectX86)
     string(REGEX REPLACE ".* Family ([0-9]+) .*" "\\1" _cpu_family "${_cpu_id}")
     string(REGEX REPLACE ".* Model ([0-9]+) .*" "\\1" _cpu_model "${_cpu_id}")
     string(REGEX REPLACE ".* Stepping ([0-9]+) .*" "\\1" _cpu_mstepping "${_cpu_id}")
-  endif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
+  endif(CMAKE_SYSTEM_NAME STREQUAL "Linux" OR CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
   if(_vendor_id STREQUAL "GenuineIntel")
     if(_cpu_family EQUAL 6)
       # taken from the Intel ORM
