--- cmake/CompilerConfiguration.cmake.orig	2024-09-04 05:25:49 UTC
+++ cmake/CompilerConfiguration.cmake
@@ -35,7 +35,7 @@ add_compile_options(
 # https://github.com/cp2k/dbcsr/issues/261 eventually check compiler version
 # (similar to -h system_alloc)
 add_compile_options(
-  "$<$<COMPILE_LANG_AND_ID:Fortran,GNU>:-mtune=native;-ffree-line-length-512;-ffree-form;-std=f2008;-fimplicit-none;-Werror=aliasing;-Werror=ampersand;-Werror=c-binding-type;-Werror=conversion;-Werror=intrinsic-shadow;-Werror=intrinsics-std;-Werror=line-truncation;-Werror=tabs;-Werror=target-lifetime;-Werror=underflow;-Werror=unused-but-set-variable;-Werror=unused-variable>"
+  "$<$<COMPILE_LANG_AND_ID:Fortran,GNU>:-ffree-line-length-512;-ffree-form;-std=f2008;-fimplicit-none;-Werror=aliasing;-Werror=ampersand;-Werror=c-binding-type;-Werror=conversion;-Werror=intrinsic-shadow;-Werror=intrinsics-std;-Werror=line-truncation;-Werror=tabs;-Werror=target-lifetime;-Werror=underflow;-Werror=unused-but-set-variable;-Werror=unused-variable>"
   "$<$<AND:$<COMPILE_LANG_AND_ID:Fortran,GNU>,$<VERSION_GREATER_EQUAL:${CMAKE_Fortran_COMPILER_VERSION},11>>:-fallow-argument-mismatch>"
   "$<$<COMPILE_LANG_AND_ID:Fortran,Intel>:-free -stand=f18 -fpp -heap-arrays>"
   "$<$<COMPILE_LANG_AND_ID:Fortran,PGI>:-Mfreeform -Mextend -Mallocatable=03>"
