--- cmake/headers.cmake.orig	2023-02-07 10:29:14.434376000 +0100
+++ cmake/headers.cmake	2023-02-07 10:29:49.032926000 +0100
@@ -23,8 +23,8 @@
   ${CMAKE_CURRENT_BINARY_DIR}/lib/chunkio/include
 
   # LuaJIT
-  ${FLB_PATH_ROOT_SOURCE}/${FLB_PATH_LIB_LUAJIT}/src
-  ${CMAKE_CURRENT_BINARY_DIR}/lib/luajit-cmake
+#  ${FLB_PATH_ROOT_SOURCE}/${FLB_PATH_LIB_LUAJIT}/src
+#  ${CMAKE_CURRENT_BINARY_DIR}/lib/luajit-cmake
 
   ${FLB_PATH_ROOT_SOURCE}/${FLB_PATH_LIB_MONKEY}/include
   ${FLB_PATH_ROOT_SOURCE}/${FLB_PATH_LIB_MONKEY}/include/monkey
