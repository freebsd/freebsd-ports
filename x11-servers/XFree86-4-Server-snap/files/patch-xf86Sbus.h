--- programs/Xserver/hw/xfree86/os-support/bus/xf86Sbus.h.orig	Wed May 22 17:38:30 2002
+++ programs/Xserver/hw/xfree86/os-support/bus/xf86Sbus.h	Fri May 16 15:47:05 2003
@@ -35,7 +35,13 @@
 #elif defined(__OpenBSD__) && defined(__sparc64__)
 /* XXX */
 #elif defined(CSRG_BASED)
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/fbio.h>
+#include <dev/ofw/openpromio.h>
+#else
 #include <machine/fbio.h>
+#endif
 #else
 #include <sun/fbio.h>
 #endif
