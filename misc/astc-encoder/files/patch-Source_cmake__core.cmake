--- Source/cmake_core.cmake.orig	2026-06-18 04:14:15 UTC
+++ Source/cmake_core.cmake
@@ -450,8 +450,6 @@ macro(astcenc_set_properties ASTCENC_TARGET_NAME ASTCE
         else()
             target_compile_options(${ASTCENC_TARGET_NAME}
                 PRIVATE
-                    $<${is_clangcl}:-march=native>
-                    $<${is_gnu_fe}:-march=native>
                     $<${is_gnu_fe}:-Wno-unused-command-line-argument>)
         endif()
     endif()
