--- vpx_ports/ppc_cpudetect.c.orig	2018-01-24 22:25:44 UTC
+++ vpx_ports/ppc_cpudetect.c
@@ -8,12 +8,6 @@
  *  be found in the AUTHORS file in the root of the source tree.
  */
 
-#include <fcntl.h>
-#include <unistd.h>
-#include <stdint.h>
-#include <asm/cputable.h>
-#include <linux/auxvec.h>
-
 #include "./vpx_config.h"
 #include "vpx_ports/ppc.h"
 
@@ -35,6 +29,13 @@ static int cpu_env_mask(void) {
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
@@ -73,6 +74,44 @@ out_close:
   close(fd);
   return flags & mask;
 }
+#elif defined(__FreeBSD__)
+#if __FreeBSD__ < 12
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#else
+#include <sys/auxv.h>
+#endif
+#include <machine/cpu.h>
+
+int ppc_simd_caps(void) {
+  int flags;
+  int mask;
+  u_long hwcap = 0;
+
+  // If VPX_SIMD_CAPS is set then allow only those capabilities.
+  if (!cpu_env_flags(&flags)) {
+    return flags;
+  }
+
+  mask = cpu_env_mask();
+
+#if __FreeBSD__ < 12
+  size_t sz = sizeof(hwcap);
+  sysctlbyname("hw.cpu_features", &hwcap, &sz, NULL, 0);
+#else
+  elf_aux_info(AT_HWCAP, &hwcap, sizeof(hwcap));
+#endif
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
