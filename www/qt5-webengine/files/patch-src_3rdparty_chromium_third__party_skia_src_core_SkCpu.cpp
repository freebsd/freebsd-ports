--- src/3rdparty/chromium/third_party/skia/src/core/SkCpu.cpp.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/skia/src/core/SkCpu.cpp
@@ -70,6 +70,20 @@
         return features;
     }
 
+#elif defined(SK_CPU_ARM64) && defined(__FreeBSD__)
+    #include <machine/armreg.h>
+
+    static uint32_t read_cpu_features() {
+        uint32_t features = 0;
+        uint64_t id_aa64isar0;
+
+        id_aa64isar0 = READ_SPECIALREG(ID_AA64ISAR0_EL1);
+        if (ID_AA64ISAR0_CRC32(id_aa64isar0) == ID_AA64ISAR0_CRC32_BASE) {
+            features |= SkCpu::CRC32;
+        }
+        return features;
+    }
+
 #elif defined(SK_CPU_ARM64) && __has_include(<sys/auxv.h>)
     #include <sys/auxv.h>
 
@@ -95,7 +109,12 @@
         const uint32_t kHWCAP_VFPv4 = (1<<16);
 
         uint32_t features = 0;
+#if defined(__FreeBSD__)
+        uint32_t hwcaps = 0;
+        elf_aux_info(AT_HWCAP, &hwcaps, sizeof(hwcaps));
+#else
         uint32_t hwcaps = getauxval(AT_HWCAP);
+#endif
         if (hwcaps & kHWCAP_NEON ) {
             features |= SkCpu::NEON;
             if (hwcaps & kHWCAP_VFPv4) { features |= SkCpu::NEON_FMA|SkCpu::VFP_FP16; }
