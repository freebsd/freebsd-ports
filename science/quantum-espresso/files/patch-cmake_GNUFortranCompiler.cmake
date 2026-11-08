--- cmake/GNUFortranCompiler.cmake.orig	2026-07-09 07:43:02 UTC
+++ cmake/GNUFortranCompiler.cmake
@@ -20,7 +20,7 @@ if(QE_ENABLE_OFFLOAD)
   else()
     message(FATAL_ERROR "Cannot derive OFFLOAD_TARGET from QE_GPU_ARCHS.")
   endif()
-  target_compile_options(qe_openmp_fortran INTERFACE "-foffload=${OFFLOAD_TARGET};-foffload-options=-lm -latomic")
+  target_compile_options(qe_openmp_fortran INTERFACE "--offload=${OFFLOAD_TARGET};--offload-options=-lm -latomic")
 
   if(OFFLOAD_TARGET STREQUAL "amdgcn-amdhsa")
     target_compile_options(qe_openmp_fortran INTERFACE "-foffload-options=${OFFLOAD_TARGET}=-march=${QE_GPU_ARCHS}")
