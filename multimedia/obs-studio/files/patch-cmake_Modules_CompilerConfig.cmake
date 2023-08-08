- prevent warnings from breaking the build

--- cmake/Modules/CompilerConfig.cmake.orig	2023-06-19 20:58:53 UTC
+++ cmake/Modules/CompilerConfig.cmake
@@ -108,7 +108,7 @@ else()
     - https://github.com/obsproject/obs-studio/issues/8850 for 13.1.1
   ]]
   add_compile_options(
-    -Werror
+    #-Werror
     -Wextra
     -Wvla
     -Wswitch
