Same change as https://github.com/cp2k/dbcsr/pull/388 PR for the current master branch.

--- cmake/CompilerConfiguration.cmake.orig	2020-11-15 21:12:10 UTC
+++ cmake/CompilerConfiguration.cmake
@@ -1,5 +1,5 @@
 if (CMAKE_Fortran_COMPILER_ID STREQUAL "GNU")
-  set(CMAKE_Fortran_FLAGS          "-ffree-form -ffree-line-length-none -std=f2008ts")
+  set(CMAKE_Fortran_FLAGS          "${CMAKE_Fortran_FLAGS} -ffree-form -ffree-line-length-none -std=f2008ts")
   set(CMAKE_Fortran_FLAGS_RELEASE  "-O3 -funroll-loops")
   set(CMAKE_Fortran_FLAGS_DEBUG    "-O0 -ggdb")
   set(CMAKE_Fortran_FLAGS_COVERAGE "-O0 -fprofile-arcs -ftest-coverage")
