--- hpijs/platform.h.orig	Wed Oct  3 03:56:37 2001
+++ hpijs/platform.h	Wed Oct  3 04:20:33 2001
@@ -13,3 +13,10 @@
 #include <string.h>
 #include <stdio.h>
 #include <math.h>
+
+#ifdef __FreeBSD__
+#include <machine/endian.h>
+#if BYTE_ORDER == LITTLE_ENDIAN
+#define _LITTLE_ENDIAN
+#endif
+#endif
