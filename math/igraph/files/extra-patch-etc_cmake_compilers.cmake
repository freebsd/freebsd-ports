--- etc/cmake/compilers.cmake.orig	2022-01-04 06:55:25 UTC
+++ etc/cmake/compilers.cmake
@@ -31,7 +31,6 @@ macro(use_all_warnings TARGET_NAME)
     target_compile_options(${TARGET_NAME} PRIVATE
       # GCC-style compilers:
       $<$<C_COMPILER_ID:GCC,Clang,AppleClang,Intel>:
-        $<$<BOOL:${IGRAPH_WARNINGS_AS_ERRORS}>:-Werror>
         -Wall -Wextra -pedantic
         -Wno-unused-function -Wno-unused-parameter -Wno-sign-compare
       >
