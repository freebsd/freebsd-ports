--- cmake/modules/FindPython3Libs.cmake.orig	2019-09-13 18:07:41 UTC
+++ cmake/modules/FindPython3Libs.cmake
@@ -101,7 +101,7 @@ endif()
 # To avoid picking up the system Python.h pre-maturely.
 set(CMAKE_FIND_FRAMEWORK LAST)
 
-set(_PYTHON3_VERSIONS 3.6 3.5 3.4 3.3 3.2 3.1 3.0)
+set(_PYTHON3_VERSIONS 3.8 3.7 3.6 3.5 3.4 3.3 3.2 3.1 3.0)
 
 if(Python3Libs_FIND_VERSION)
     if(Python3Libs_FIND_VERSION_COUNT GREATER 1)
