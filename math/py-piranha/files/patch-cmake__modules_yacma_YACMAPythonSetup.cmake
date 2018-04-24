--- cmake_modules/yacma/YACMAPythonSetup.cmake.orig	2018-03-30 18:25:11 UTC
+++ cmake_modules/yacma/YACMAPythonSetup.cmake
@@ -6,8 +6,8 @@ endif()
 include(YACMACompilerLinkerSettings)
 
 # Find Python interpreter and libraries. This is the order suggested by CMake's documentation.
-find_package(PythonInterp REQUIRED)
-find_package(PythonLibs REQUIRED)
+#find_package(PythonInterp REQUIRED)
+#find_package(PythonLibs REQUIRED)
 message(STATUS "Python interpreter: ${PYTHON_EXECUTABLE}")
 message(STATUS "Python libraries: ${PYTHON_LIBRARIES}")
 message(STATUS "Python include dirs: ${PYTHON_INCLUDE_DIRS}")
