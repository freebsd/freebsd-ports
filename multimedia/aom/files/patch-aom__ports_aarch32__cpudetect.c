- Assume NEON is enabled on armv7
- Implement runtime detection on FreeBSD

--- aom_ports/aarch32_cpudetect.c.orig	2023-11-30 23:18:12 UTC
+++ aom_ports/aarch32_cpudetect.c
@@ -12,7 +12,7 @@
 
 #include "arm_cpudetect.h"
 
-#if !CONFIG_RUNTIME_CPU_DETECT
+#if !CONFIG_RUNTIME_CPU_DETECT || defined(__ARM_NEON)
 
 static int arm_get_cpu_caps(void) {
   // This function should actually be a no-op. There is no way to adjust any of
@@ -55,9 +55,23 @@ static int arm_get_cpu_caps(void) {
   return flags;
 }
 
-#elif defined(__linux__)  // end defined(AOM_USE_ANDROID_CPU_FEATURES)
+#elif defined(__linux__) || defined(__FreeBSD__)  // end defined(AOM_USE_ANDROID_CPU_FEATURES)
 
 #include <sys/auxv.h>
+
+#if defined(__FreeBSD__)
+static unsigned long getauxval(unsigned long type)
+{
+    /* Only AT_HWCAP* return unsigned long */
+    if (type != AT_HWCAP && type != AT_HWCAP2) {
+        return 0;
+    }
+
+    unsigned long ret = 0;
+    elf_aux_info(type, &ret, sizeof(ret));
+    return ret;
+}
+#endif
 
 // Define hwcap values ourselves: building with an old auxv header where these
 // hwcap values are not defined should not prevent features from being enabled.
