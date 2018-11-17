- Assume NEON is enabled on aarch64
- Implement NEON runtime detection on FreeBSD

--- aom_ports/arm_cpudetect.c.orig	2018-11-16 20:24:20 UTC
+++ aom_ports/arm_cpudetect.c
@@ -38,7 +38,7 @@ static int arm_cpu_env_mask(void) {
   return env && *env ? (int)strtol(env, NULL, 0) : ~0;
 }
 
-#if !CONFIG_RUNTIME_CPU_DETECT
+#if !CONFIG_RUNTIME_CPU_DETECT || defined(__ARM_NEON)
 
 int aom_arm_cpu_caps(void) {
   /* This function should actually be a no-op. There is no way to adjust any of
@@ -143,7 +143,61 @@ int aom_arm_cpu_caps(void) {
   }
   return flags & mask;
 }
-#else  /* end __linux__ */
+#elif defined(__FreeBSD__)
+
+#if 0 // __has_include(<sys/auxv.h>)
+#include <sys/auxv.h>
+#else
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <elf.h>
+#include <errno.h>
+#include <unistd.h>
+
+static unsigned long getauxval(unsigned long type) {
+  Elf_Auxinfo auxv[AT_COUNT];
+  size_t len = sizeof(auxv);
+  int mib[] = {
+    CTL_KERN,
+    KERN_PROC,
+    KERN_PROC_AUXV,
+    getpid(),
+  };
+
+  if (sysctl(mib, nitems(mib), auxv, &len, NULL, 0) != -1) {
+    for (size_t i = 0; i < nitems(auxv); i++)
+      if ((unsigned long)auxv[i].a_type == type)
+        return auxv[i].a_un.a_val;
+
+    errno = ENOENT;
+  }
+  return 0;
+}
+#endif
+
+#ifndef AT_HWCAP
+#define AT_HWCAP 25 /* 16 on Linux */
+#endif
+
+#ifndef HWCAP_NEON
+#define HWCAP_NEON (1 << 12)
+#endif
+
+int aom_arm_cpu_caps(void) {
+  int flags;
+  int mask;
+  unsigned long hwcaps;
+  if (!arm_cpu_env_flags(&flags)) {
+    return flags;
+  }
+  mask = arm_cpu_env_mask();
+  hwcaps = getauxval(AT_HWCAP);
+#if HAVE_NEON
+  if (hwcaps & HWCAP_NEON) flags |= HAS_NEON;
+#endif
+  return flags & mask;
+}
+#else /* end __FreeBSD__ */
 #error \
     "--enable-runtime-cpu-detect selected, but no CPU detection method " \
 "available for your platform. Reconfigure with --disable-runtime-cpu-detect."
