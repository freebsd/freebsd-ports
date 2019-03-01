- Don't enable NEON on armv6 similar to build/cmake/rtcd.pl

--- build/cmake/cpu.cmake.orig	2018-11-16 20:24:20 UTC
+++ build/cmake/cpu.cmake
@@ -9,7 +9,7 @@
 # can obtain it at www.aomedia.org/license/patent.
 #
 
-if("${AOM_TARGET_CPU}" MATCHES "^arm")
+if("${AOM_TARGET_CPU}" MATCHES "^arm" AND NOT "${AOM_TARGET_CPU}" MATCHES "^armv6")
   set(ARCH_ARM 1)
   set(RTCD_ARCH_ARM "yes")
 
