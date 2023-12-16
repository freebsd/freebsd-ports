- Don't enable NEON on armv6 similar to build/cmake/rtcd.pl

--- build/cmake/cpu.cmake.orig	2023-11-30 23:18:12 UTC
+++ build/cmake/cpu.cmake
@@ -61,7 +61,7 @@ if("${AOM_TARGET_CPU}" STREQUAL "arm64")
     endif()
   endforeach()
 
-elseif("${AOM_TARGET_CPU}" MATCHES "^arm")
+elseif("${AOM_TARGET_CPU}" MATCHES "^arm" AND NOT "${AOM_TARGET_CPU}" MATCHES "^armv6")
   set(AOM_ARCH_ARM 1)
   set(RTCD_ARCH_ARM "yes")
 
