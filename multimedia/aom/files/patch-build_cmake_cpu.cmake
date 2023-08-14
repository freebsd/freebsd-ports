- Don't enable NEON on armv6 similar to build/cmake/rtcd.pl

--- build/cmake/cpu.cmake.orig	2023-08-14 21:22:47 UTC
+++ build/cmake/cpu.cmake
@@ -9,7 +9,7 @@
 # can obtain it at www.aomedia.org/license/patent.
 #
 
-if("${AOM_TARGET_CPU}" MATCHES "^arm")
+if("${AOM_TARGET_CPU}" MATCHES "^arm" AND NOT "${AOM_TARGET_CPU}" MATCHES "^armv6")
   set(AOM_ARCH_ARM 1)
   if("${AOM_TARGET_CPU}" STREQUAL "arm64")
     set(AOM_ARCH_AARCH64 1)
