- Implement VSX detection on FreeBSD

--- aom_ports/ppc_cpudetect.c.orig	2018-06-25 14:54:59 UTC
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
@@ -75,6 +76,36 @@ out_close:
   close(fd);
   return flags & mask;
 }
+#elif defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <machine/cpu.h>
+
+int ppc_simd_caps(void) {
+  int flags;
+  int mask;
+  u_long cpu_features = 0;
+  size_t sz = sizeof(cpu_features);
+
+  // If AOM_SIMD_CAPS is set then allow only those capabilities.
+  if (!cpu_env_flags(&flags)) {
+    return flags;
+  }
+
+  mask = cpu_env_mask();
+
+  sysctlbyname("hw.cpu_features", &cpu_features, &sz, NULL, 0);
+#if HAVE_VSX
+  if (cpu_features & PPC_FEATURE_HAS_VSX) flags |= HAS_VSX;
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
