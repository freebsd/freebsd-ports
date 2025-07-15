Strip the _POSIX_C_SOURCE=200809L define again, our libc++ breaks claiming
that a set included from locale cannot find isascii()...

--- vendor/source/igraph/etc/cmake/compilers.cmake.orig	2025-06-11 00:03:00 UTC
+++ vendor/source/igraph/etc/cmake/compilers.cmake
@@ -1,13 +1,5 @@ include(CheckCCompilerFlag)
 include(CheckCCompilerFlag)
 
-# Enable POSIX features. This needs to be set here instead of in source files so
-# that it affects CMake-based feature tests.
-#
-# See:
-#  - https://pubs.opengroup.org/onlinepubs/007904875/functions/xsh_chap02_02.html
-#  - https://www.gnu.org/software/libc/manual/html_node/Feature-Test-Macros.html
-add_compile_definitions(_POSIX_C_SOURCE=200809L)
-
 if(MSVC)
   add_compile_options(/FS)
   add_compile_definitions(_CRT_SECURE_NO_WARNINGS) # necessary to compile for UWP
