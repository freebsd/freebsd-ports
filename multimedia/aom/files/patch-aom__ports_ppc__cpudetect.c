- Implement VSX detection on FreeBSD

--- aom_ports/ppc_cpudetect.c.orig	2021-07-20 22:23:15 UTC
+++ aom_ports/ppc_cpudetect.c
@@ -9,12 +9,6 @@
  * PATENTS file, you can obtain it at www.aomedia.org/license/patent.
  */
 
-#include <fcntl.h>
-#include <unistd.h>
-#include <stdint.h>
-#include <asm/cputable.h>
-#include <linux/auxvec.h>
-
 #include "config/aom_config.h"
 
 #include "aom_ports/ppc.h"
@@ -37,6 +31,13 @@ static int cpu_env_mask(void) {
   return env && *env ? (int)strtol(env, NULL, 0) : ~0;
 }
 
+#if defined(__linux__)
+#include <fcntl.h>
+#include <unistd.h>
+#include <stdint.h>
+#include <asm/cputable.h>
+#include <linux/auxvec.h>
+
 int ppc_simd_caps(void) {
   int flags;
   int mask;
@@ -75,6 +76,34 @@ out_close:
   close(fd);
   return flags & mask;
 }
+#elif defined(__FreeBSD__)
+#include <sys/auxv.h>
+#include <machine/cpu.h>
+
+int ppc_simd_caps(void) {
+  int flags;
+  int mask;
+  u_long hwcap = 0;
+
+  // If AOM_SIMD_CAPS is set then allow only those capabilities.
+  if (!cpu_env_flags(&flags)) {
+    return flags;
+  }
+
+  mask = cpu_env_mask();
+
+  elf_aux_info(AT_HWCAP, &hwcap, sizeof(hwcap));
+#if HAVE_VSX
+  if (hwcap & PPC_FEATURE_HAS_VSX) flags |= HAS_VSX;
+#endif
+
+  return flags & mask;
+}
+#else
+#error \
+    "--enable-runtime-cpu-detect selected, but no CPU detection method " \
+"available for your platform. Reconfigure with --disable-runtime-cpu-detect."
+#endif   /* end __FreeBSD__ */
 #else
 // If there is no RTCD the function pointers are not used and can not be
 // changed.
