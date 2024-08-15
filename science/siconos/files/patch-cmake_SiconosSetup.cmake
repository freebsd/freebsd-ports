- fix the python version to be same as in the port

--- cmake/SiconosSetup.cmake.orig	2024-08-02 04:37:45 UTC
+++ cmake/SiconosSetup.cmake
@@ -21,7 +21,7 @@ include_directories($<BUILD_INTERFACE:${CMAKE_BINARY_D
 
 # Add extra logs about git references(branch name, commit number...)
 # Useful for documentation and continuous integration
-find_package(Git)
+#find_package(Git)
 if(Git_FOUND)
   execute_process(COMMAND
     ${GIT_EXECUTABLE} -C ${CMAKE_SOURCE_DIR} rev-parse
@@ -61,9 +61,9 @@ endif()
 #  --> look for python framework when all other possibilities failed.
 set(Python_FIND_FRAMEWORK LAST)
 if(WITH_PYTHON_WRAPPER)
-  find_package(Python COMPONENTS Development Interpreter NumPy REQUIRED)
+  find_package(Python ${FREEBSD_PYTHON_VER} EXACT COMPONENTS Development Interpreter NumPy REQUIRED)
 else()
-  find_package(Python COMPONENTS Interpreter REQUIRED)
+  find_package(Python ${FREEBSD_PYTHON_VER} EXACT COMPONENTS Interpreter REQUIRED)
 endif()
 # For backward compat ...
 set(PYTHON_EXECUTABLE ${Python_EXECUTABLE})
