- Assume NEON is enabled on aarch64
- Implement NEON runtime detection on FreeBSD

--- aom_ports/arm_cpudetect.c.orig	2021-10-01 00:23:06 UTC
+++ aom_ports/arm_cpudetect.c
@@ -38,7 +38,7 @@ static int arm_cpu_env_mask(void) {
   return env && *env ? (int)strtol(env, NULL, 0) : ~0;
 }
 
-#if !CONFIG_RUNTIME_CPU_DETECT || defined(__APPLE__)
+#if !CONFIG_RUNTIME_CPU_DETECT || defined(__ARM_NEON) || defined(__APPLE__)
 
 int aom_arm_cpu_caps(void) {
   /* This function should actually be a no-op. There is no way to adjust any of
@@ -143,7 +143,25 @@ int aom_arm_cpu_caps(void) {
   }
   return flags & mask;
 }
-#else  /* end __linux__ */
+#elif defined(__FreeBSD__)
+
+#include <sys/auxv.h>
+
+int aom_arm_cpu_caps(void) {
+  int flags;
+  int mask;
+  u_long hwcap = 0;
+  if (!arm_cpu_env_flags(&flags)) {
+    return flags;
+  }
+  mask = arm_cpu_env_mask();
+  elf_aux_info(AT_HWCAP, &hwcap, sizeof(hwcap));
+#if HAVE_NEON
+  if (hwcap & HWCAP_NEON) flags |= HAS_NEON;
+#endif
+  return flags & mask;
+}
+#else  /* end __FreeBSD__ */
 #error \
     "Runtime CPU detection selected, but no CPU detection method " \
 "available for your platform. Rerun cmake with -DCONFIG_RUNTIME_CPU_DETECT=0."
