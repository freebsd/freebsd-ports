--- cmake/CompilerConfiguration.cmake.orig	2026-07-24 05:31:47 UTC
+++ cmake/CompilerConfiguration.cmake
@@ -52,7 +52,6 @@ add_compile_options(
 
 # -- Apple Silicon + GCC: -march=native expands internally to -march=apple-m1
 # (invalid). Use -mcpu=native instead.
-set(_CP2K_GNU_NATIVE_TUNE "-march=native;-mtune=native")
 if(APPLE
    AND CMAKE_SYSTEM_PROCESSOR STREQUAL "arm64"
    AND (CMAKE_Fortran_COMPILER_ID STREQUAL "GNU"
