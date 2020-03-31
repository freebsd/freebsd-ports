Regressed by https://svnweb.freebsd.org/changeset/base/324815

gfx/skia/skia/src/core/SkCpu.cpp:81:27: error: use of undeclared identifier 'getauxval'
        uint32_t hwcaps = getauxval(AT_HWCAP);
                          ^

--- gfx/skia/skia/src/core/SkCpu.cpp.orig	2020-02-10 09:43:20 UTC
+++ gfx/skia/skia/src/core/SkCpu.cpp
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
 
