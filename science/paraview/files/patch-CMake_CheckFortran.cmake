--- CMake/CheckFortran.cmake.orig	2026-09-29 17:25:09 UTC
+++ CMake/CheckFortran.cmake
@@ -9,7 +9,7 @@ function (check_fortran_support)
   message(STATUS "${_desc}")
   file(REMOVE_RECURSE "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/CheckFortran")
   file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/CheckFortran/CMakeLists.txt"
-    "cmake_minimum_required(VERSION 3.3)
+    "cmake_minimum_required(VERSION 3.5)
 project(CheckFortran Fortran)
 file(WRITE \"\${CMAKE_CURRENT_BINARY_DIR}/result.cmake\"
 \"set(CMAKE_Fortran_COMPILER \\\"\${CMAKE_Fortran_COMPILER}\\\")\\n\"
