--- cmake/GNUFortranCompiler.cmake.orig	2024-02-29 10:18:05 UTC
+++ cmake/GNUFortranCompiler.cmake
@@ -29,7 +29,7 @@ else()
 
   target_link_options(qe_openmp_fortran INTERFACE "$<$<LINK_LANGUAGE:Fortran>:${OpenMP_Fortran_FLAGS}>")
 else()
-  target_compile_options(qe_openmp_fortran INTERFACE "-foffload=disable")
+  target_compile_options(qe_openmp_fortran INTERFACE "--offload=disable")
 endif()
 
 ############################################################
