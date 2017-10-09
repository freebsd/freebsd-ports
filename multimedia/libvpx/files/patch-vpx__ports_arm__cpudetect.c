--- vpx_ports/arm_cpudetect.c.orig	2017-01-12 20:27:27 UTC
+++ vpx_ports/arm_cpudetect.c
@@ -147,6 +147,60 @@ int arm_cpu_caps(void) {
   }
   return flags & mask;
 }
+#elif defined(__FreeBSD__)
+
+#if __has_include(<sys/auxv.h>)
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
+int arm_cpu_caps(void) {
+  int flags;
+  int mask;
+  unsigned long hwcaps;
+  if (!arm_cpu_env_flags(&flags)) {
+    return flags;
+  }
+  mask = arm_cpu_env_mask();
+  hwcaps = getauxval(AT_HWCAP);
+#if HAVE_NEON || HAVE_NEON_ASM
+  if (hwcaps & HWCAP_NEON) flags |= HAS_NEON;
+#endif
+  return flags & mask;
+}
 #else  /* end __linux__ */
 #error \
     "--enable-runtime-cpu-detect selected, but no CPU detection method " \
