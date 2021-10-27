--- .CMake/compiler_opts.cmake.orig	2021-10-13 10:39:00 UTC
+++ .CMake/compiler_opts.cmake
@@ -51,7 +51,6 @@ if(CMAKE_C_COMPILER_ID MATCHES "Clang|GNU")
 endif()
 
 if(CMAKE_C_COMPILER_ID MATCHES "Clang")
-    add_compile_options(-Werror)
     add_compile_options(-Wall)
     add_compile_options(-Wextra)
     add_compile_options(-Wpedantic)
