--- etc/cmake/compilers.cmake.orig	2024-06-15 14:00:49 UTC
+++ etc/cmake/compilers.cmake
@@ -6,7 +6,7 @@ include(CheckCCompilerFlag)
 # See:
 #  - https://pubs.opengroup.org/onlinepubs/007904875/functions/xsh_chap02_02.html
 #  - https://www.gnu.org/software/libc/manual/html_node/Feature-Test-Macros.html
-add_compile_definitions(_POSIX_C_SOURCE=200809L)
+#add_compile_definitions(_POSIX_C_SOURCE=200809L)
 
 if(MSVC)
   add_compile_options(/FS)
