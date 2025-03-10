--- gfx/skia/skia/src/core/SkCpu.cpp.orig	2025-02-24 16:56:14 UTC
+++ gfx/skia/skia/src/core/SkCpu.cpp
@@ -89,6 +89,26 @@
     }
 #endif
 
+#if (SK_CPU_ARM32) && defined(__FreeBSD__)
+    #include <sys/auxv.h>
+
+    static uint32_t read_cpu_features() {
+        unsigned long caps = 0;
+        uint32_t features = 0;
+
+        elf_aux_info(AT_HWCAP, &caps, sizeof caps);
+
+        if (caps & HWCAP_NEON) {
+            features |= SkCpu::NEON;
+            if (caps & HWCAP_VFPv4) {
+                features |= SkCpu::NEON_FMA|SkCpu::VFP_FP16;
+            }
+        }
+
+        return features;
+    }
+#endif
+
 uint32_t SkCpu::gCachedFeatures = 0;
 
 void SkCpu::CacheRuntimeFeatures() {
