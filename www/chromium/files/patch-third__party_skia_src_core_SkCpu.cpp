--- third_party/skia/src/core/SkCpu.cpp.orig	2018-06-13 00:12:11.000000000 +0200
+++ third_party/skia/src/core/SkCpu.cpp	2018-07-19 20:40:05.469146000 +0200
@@ -78,6 +78,8 @@
     #include <sys/auxv.h>
 
     static uint32_t read_cpu_features() {
+return 0;
+#if 0
         const uint32_t kHWCAP_CRC32   = (1<< 7),
                        kHWCAP_ASIMDHP = (1<<10);
 
@@ -86,6 +88,7 @@
         if (hwcaps & kHWCAP_CRC32  ) { features |= SkCpu::CRC32; }
         if (hwcaps & kHWCAP_ASIMDHP) { features |= SkCpu::ASIMDHP; }
         return features;
+#endif
     }
 
 #elif defined(SK_CPU_ARM32) && __has_include(<sys/auxv.h>) && \
