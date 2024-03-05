--- VTK/CMake/vtkCompilerChecks.cmake.orig	2024-02-28 20:42:21 UTC
+++ VTK/CMake/vtkCompilerChecks.cmake
@@ -33,7 +33,7 @@ if(NOT VTK_IGNORE_CMAKE_CXX11_CHECKS)
   # Needed to make sure libraries and executables not built by the
   # vtkModuleMacros still have the C++11 compiler flags enabled
   # Wrap this in an escape hatch for unknown compilers
-  set(CMAKE_CXX_STANDARD 11)
+  set(CMAKE_CXX_STANDARD 17)
   set(CMAKE_CXX_STANDARD_REQUIRED True)
   set(CMAKE_CXX_EXTENSIONS False)
 endif()
