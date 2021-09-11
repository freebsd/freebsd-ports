--- vpx_ports/arm_cpudetect.c.orig	2021-03-18 19:59:46 UTC
+++ vpx_ports/arm_cpudetect.c
@@ -38,7 +38,7 @@ static int arm_cpu_env_mask(void) {
   return env && *env ? (int)strtol(env, NULL, 0) : ~0;
 }
 
-#if !CONFIG_RUNTIME_CPU_DETECT
+#if !CONFIG_RUNTIME_CPU_DETECT || defined(__ARM_NEON)
 
 int arm_cpu_caps(void) {
   /* This function should actually be a no-op. There is no way to adjust any of
@@ -147,7 +147,25 @@ int arm_cpu_caps(void) {
   }
   return flags & mask;
 }
-#else  /* end __linux__ */
+#elif defined(__FreeBSD__)
+
+#include <sys/auxv.h>
+
+int arm_cpu_caps(void) {
+  int flags;
+  int mask;
+  u_long hwcap = 0;
+  if (!arm_cpu_env_flags(&flags)) {
+    return flags;
+  }
+  mask = arm_cpu_env_mask();
+  elf_aux_info(AT_HWCAP, &hwcap, sizeof(hwcap));
+#if HAVE_NEON || HAVE_NEON_ASM
+  if (hwcap & HWCAP_NEON) flags |= HAS_NEON;
+#endif
+  return flags & mask;
+}
+#else  /* end __FreeBSD__ */
 #error \
     "--enable-runtime-cpu-detect selected, but no CPU detection method " \
 "available for your platform. Reconfigure with --disable-runtime-cpu-detect."
