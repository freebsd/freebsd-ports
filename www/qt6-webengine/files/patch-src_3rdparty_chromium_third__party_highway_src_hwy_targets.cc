--- src/3rdparty/chromium/third_party/highway/src/hwy/targets.cc.orig	2026-05-08 07:54:08 UTC
+++ src/3rdparty/chromium/third_party/highway/src/hwy/targets.cc
@@ -36,7 +36,11 @@
 // sys/auxv.h does not always include asm/hwcap.h, or define HWCAP*, hence we
 // still include this directly. See #1199.
 #ifndef TOOLCHAIN_MISS_ASM_HWCAP_H
+#ifdef __powerpc64__
+#include <asm/cputable.h>
+#else
 #include <asm/hwcap.h>
+#endif
 #endif
 #if HWY_HAVE_AUXV
 #include <sys/auxv.h>
