--- CMake/ParaViewCompilerChecks.cmake.orig	2025-03-31 14:04:52 UTC
+++ CMake/ParaViewCompilerChecks.cmake
@@ -28,12 +28,12 @@ endif ()
   message(FATAL_ERROR "Intel C++ (ICC) 14.0 or later is required.")
 endif ()
 
-# Make sure we have C++11 enabled.
+# Make sure we have C++17 enabled.
 if(NOT PARAVIEW_IGNORE_CMAKE_CXX11_CHECKS)
   # Needed to make sure libraries and executables not built by the
-  # vtkModuleMacros still have the C++11 compiler flags enabled
+  # vtkModuleMacros still have the C++17 compiler flags enabled
   # Wrap this in an escape hatch for unknown compilers
-  set(CMAKE_CXX_STANDARD 11)
+  set(CMAKE_CXX_STANDARD 17)
   set(CMAKE_CXX_STANDARD_REQUIRED True)
   set(CMAKE_CXX_EXTENSIONS False)
 endif()
