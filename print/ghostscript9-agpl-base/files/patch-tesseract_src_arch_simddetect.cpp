--- tesseract/src/arch/simddetect.cpp.orig	2021-09-27 07:44:02 UTC
+++ tesseract/src/arch/simddetect.cpp
@@ -40,10 +40,13 @@
 #if defined(HAVE_NEON) && !defined(__aarch64__)
 #ifdef ANDROID
 #include <cpu-features.h>
-#else
+#elif defined(__linux__)
 /* Assume linux */
 #include <sys/auxv.h>
 #include <asm/hwcap.h>
+#elif defined(__FreeBSD__)
+#include <sys/auxv.h>
+#include <sys/elf.h>
 #endif
 #endif
 
@@ -188,9 +191,15 @@ SIMDDetect::SIMDDetect() {
       neon_available_ = (android_getCpuFeatures() &
                          ANDROID_CPU_ARM_FEATURE_NEON);
   }
-#else
+#elif defined(__linux__)
   /* Assume linux */
   neon_available_ = getauxval(AT_HWCAP) & HWCAP_NEON;
+#elif defined(__FreeBSD__)
+  unsigned long hwcap = 0;
+  elf_aux_info(AT_HWCAP, &hwcap, sizeof hwcap);
+  neon_available_ = hwcap & HWCAP_NEON;
+#else
+  neon_available_ = 0;
 #endif
 #endif
 
