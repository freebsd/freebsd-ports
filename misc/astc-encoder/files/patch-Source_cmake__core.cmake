--- Source/cmake_core.cmake.orig	2025-04-14 08:46:50 UTC
+++ Source/cmake_core.cmake
@@ -437,8 +437,6 @@ macro(astcenc_set_properties ASTCENC_TARGET_NAME ASTCE
         else()
             target_compile_options(${ASTCENC_TARGET_NAME}
                 PRIVATE
-                    $<${is_clangcl}:-mcpu=native -march=native>
-                    $<${is_gnu_fe}:-mcpu=native -march=native>
                     $<${is_gnu_fe}:-Wno-unused-command-line-argument>)
         endif()
     endif()
