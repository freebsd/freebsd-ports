--- cmake/Build.cmake.orig	2024-08-31 06:52:24 UTC
+++ cmake/Build.cmake
@@ -18,7 +18,6 @@ elseif(UNIX)
   add_compile_options(/WX)
 elseif(UNIX)
   message(STATUS "Enabling warnings as errors (GNU/Clang)")
-  add_compile_options(-Werror)
 endif()
 
 macro(post_config)
