--- cmake/Dependencies.cmake.orig	2023-05-08 19:58:16 UTC
+++ cmake/Dependencies.cmake
@@ -1,3 +1,5 @@
+set(CMAKE_CXX_STANDARD 17)
+
 # RPATH stuff
 # see https://cmake.org/Wiki/CMake_RPATH_handling
 if(APPLE)
