--- cmake/GNUFortranCompiler.cmake.orig	2024-10-21 12:38:43 UTC
+++ cmake/GNUFortranCompiler.cmake
@@ -29,7 +29,7 @@ else()
 
   target_link_options(qe_openmp_fortran INTERFACE "$<$<LINK_LANGUAGE:Fortran>:${OpenMP_Fortran_FLAGS}>")
 else()
-  target_compile_options(qe_openmp_fortran INTERFACE "$<$<COMPILE_LANGUAGE:Fortran>:-foffload=disable>")
+  target_compile_options(qe_openmp_fortran INTERFACE "$<$<COMPILE_LANGUAGE:Fortran>:--offload=disable>")
 endif()
 
 ############################################################
