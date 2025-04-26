--- src/3rdparty/chromium/third_party/skia/src/core/SkCpu.cpp.orig	2025-03-06 09:26:10 UTC
+++ src/3rdparty/chromium/third_party/skia/src/core/SkCpu.cpp
@@ -72,6 +72,23 @@
         return features;
     }
 
+#elif defined(SK_CPU_ARM64) && defined(__FreeBSD__)
+    #include <machine/armreg.h>
+    #ifndef ID_AA64ISAR0_CRC32_VAL
+    #define ID_AA64ISAR0_CRC32_VAL ID_AA64ISAR0_CRC32
+    #endif
+
+    static uint32_t read_cpu_features() {
+      uint32_t features = 0;
+      uint64_t id_aa64isar0;
+
+      id_aa64isar0 = READ_SPECIALREG(id_aa64isar0_el1);
+      if (ID_AA64ISAR0_CRC32_VAL(id_aa64isar0) == ID_AA64ISAR0_CRC32_BASE) {
+        features |= SkCpu::CRC32;
+      }
+      return features;
+    }
+
 #elif defined(SK_CPU_ARM64) && __has_include(<sys/auxv.h>)
     #include <sys/auxv.h>
 
@@ -110,6 +127,22 @@
                           || 0 == memcmp(kMongoose3, buf, SK_ARRAY_COUNT(buf))) {
                 features &= ~(SkCpu::ASIMDHP);
             }
+        }
+        return features;
+    }
+
+#elif defined(SK_CPU_ARM32) && defined(__FreeBSD__)
+    #include <sys/auxv.h>
+
+    static uint32_t read_cpu_features() {
+        uint32_t features = 0;
+        unsigned long hwcaps = 0;
+
+        elf_aux_info(AT_HWCAP, &hwcaps, sizeof hwcaps);
+
+        if (hwcaps & HWCAP_NEON ) {
+            features |= SkCpu::NEON;
+            if (hwcaps & HWCAP_VFPv4) { features |= SkCpu::NEON_FMA|SkCpu::VFP_FP16; }
         }
         return features;
     }
