--- cmake/python.cmake.orig	2020-08-03 18:30:02 UTC
+++ cmake/python.cmake
@@ -23,7 +23,7 @@ if(UNIX AND NOT APPLE)
 endif()
 
 # Find Python
-find_package(Python REQUIRED COMPONENTS Interpreter Development)
+find_package(Python ${FREEBSD_PYTHON_VER} EXACT REQUIRED COMPONENTS Interpreter Development)
 
 if(Python_VERSION VERSION_GREATER_EQUAL 3)
   list(APPEND CMAKE_SWIG_FLAGS "-py3")
