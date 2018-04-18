--- third_party/skia/src/core/SkCpu.cpp	2018-04-13 18:15:13 UTC
+++ third_party/skia/src/core/SkCpu.cpp
@@ -78,12 +78,15 @@
     #include <sys/auxv.h>
 
     static uint32_t read_cpu_features() {
+return 0;
+#if 0
         const uint32_t kHWCAP_CRC32 = (1<<7);
 
         uint32_t features = 0;
         uint32_t hwcaps = getauxval(AT_HWCAP);
         if (hwcaps & kHWCAP_CRC32) { features |= SkCpu::CRC32; }
         return features;
+#endif
     }
 
 #elif defined(SK_CPU_ARM32) && __has_include(<sys/auxv.h>) && \
