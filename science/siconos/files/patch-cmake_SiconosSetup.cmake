- fix the python version to be same as in the port

--- cmake/SiconosSetup.cmake.orig	2021-04-13 09:54:11 UTC
+++ cmake/SiconosSetup.cmake
@@ -61,9 +61,9 @@ endif()
 #  --> look for python framework when all other possibilities failed.
 set(Python3_FIND_FRAMEWORK LAST)
 if(WITH_PYTHON_WRAPPER)
-  find_package(Python3 COMPONENTS Development Interpreter NumPy REQUIRED)
+  find_package(Python3 ${FREEBSD_PYTHON_VER} EXACT COMPONENTS Development Interpreter NumPy REQUIRED)
 else()
-  find_package(Python3 COMPONENTS Interpreter REQUIRED)
+  find_package(Python3 ${FREEBSD_PYTHON_VER} EXACT COMPONENTS Interpreter REQUIRED)
 endif()
 # For backward compat ...
 set(PYTHON_EXECUTABLE ${Python3_EXECUTABLE})
