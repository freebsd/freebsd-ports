--- src/gvnc.h.orig	2008-03-24 11:39:20.000000000 -0400
+++ src/gvnc.h	2008-03-24 11:40:22.000000000 -0400
@@ -3,6 +3,19 @@
 
 #include <glib.h>
 #include <stdint.h>
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+
+#define __BYTE_ORDER		_BYTE_ORDER
+#define __LITTLE_ENDIAN		_LITTLE_ENDIAN
+#define __BIG_ENDIAN		_BIG_ENDIAN
+
+#define bswap_16		bswap16
+#define bswap_32		bswap32
+#define bswap_64		bswap64
+#else
+#include <endian.h>
+#endif
 
 struct gvnc;
 
