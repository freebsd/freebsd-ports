--- Source/cmake_core.cmake.orig	2024-11-15 11:22:40 UTC
+++ Source/cmake_core.cmake
@@ -170,7 +170,6 @@ macro(astcenc_set_properties ASTCENC_TARGET_NAME ASTCE
             $<${is_gnu_fe}:-Wall>
             $<${is_gnu_fe}:-Wextra>
             $<${is_gnu_fe}:-Wpedantic>
-            $<${is_gnu_fe}:-Werror>
             $<${is_gnu_fe}:-Wshadow>
             $<${is_gnu_fe}:-Wdouble-promotion>
             $<${is_clang}:-Wdocumentation>
@@ -449,8 +448,6 @@ macro(astcenc_set_properties ASTCENC_TARGET_NAME ASTCE
         else()
             target_compile_options(${ASTCENC_TARGET_NAME}
                 PRIVATE
-                    $<${is_clangcl}:-mcpu=native -march=native>
-                    $<${is_gnu_fe}:-mcpu=native -march=native>
                     $<${is_gnu_fe}:-Wno-unused-command-line-argument>)
         endif()
     endif()
