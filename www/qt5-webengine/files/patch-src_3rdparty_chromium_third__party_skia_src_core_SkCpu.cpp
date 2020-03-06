--- src/3rdparty/chromium/third_party/skia/src/core/SkCpu.cpp	2019-10-21 10:14:54 UTC
+++ src/3rdparty/chromium/third_party/skia/src/core/SkCpu.cpp
@@ -70,6 +70,23 @@
         return features;
     }
 
+#elif defined(SK_CPU_ARM64) && defined(__FreeBSD__)
+    #include <machine/armreg.h>
+    #ifndef ID_AA64ISAR0_CRC32_VAL
+    #define ID_AA64ISAR0_CRC32_VAL ID_AA64ISAR0_CRC32
+    #endif
+
+    static uint32_t read_cpu_features() {
+        uint32_t features = 0;
+        uint64_t id_aa64isar0;
+
+        id_aa64isar0 = READ_SPECIALREG(id_aa64isar0_el1);
+        if (ID_AA64ISAR0_CRC32_VAL(id_aa64isar0) == ID_AA64ISAR0_CRC32_BASE) {
+            features |= SkCpu::CRC32;
+        }
+        return features;
+    }
+
 #elif defined(SK_CPU_ARM64) && __has_include(<sys/auxv.h>)
     #include <sys/auxv.h>
 
@@ -78,7 +95,12 @@
                        kHWCAP_ASIMDHP = (1<<10);
 
         uint32_t features = 0;
+#if defined(__FreeBSD__)
+        uint32_t hwcaps = 0;
+        elf_aux_info(AT_HWCAP, &hwcaps, sizeof(hwcaps));
+#else
         uint32_t hwcaps = getauxval(AT_HWCAP);
+#endif
         if (hwcaps & kHWCAP_CRC32  ) { features |= SkCpu::CRC32; }
         if (hwcaps & kHWCAP_ASIMDHP) { features |= SkCpu::ASIMDHP; }
         return features;
