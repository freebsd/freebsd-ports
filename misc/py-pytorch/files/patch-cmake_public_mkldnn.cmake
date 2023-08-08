--- cmake/public/mkldnn.cmake.orig	2022-12-16 00:23:46 UTC
+++ cmake/public/mkldnn.cmake
@@ -4,7 +4,7 @@ if(CPU_AARCH64)
   include(${CMAKE_CURRENT_LIST_DIR}/ComputeLibrary.cmake)
 endif()
 
-find_package(MKLDNN QUIET)
+find_package(MKLDNN REQUIRED)
 
 if(NOT TARGET caffe2::mkldnn)
   add_library(caffe2::mkldnn INTERFACE IMPORTED)
