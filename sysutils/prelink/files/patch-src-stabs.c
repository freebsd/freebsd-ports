diff -Nur src/stabs.c src/stabs.c
--- src/stabs.c	2013-02-19 23:54:34.000000000 +0200
+++ src/stabs.c	2013-02-19 23:50:31.000000000 +0200
@@ -17,8 +17,23 @@
 
 #include <config.h>
 #include <assert.h>
+
+#if HAVE_BYTESWAP_H
 #include <byteswap.h>
+#elif HAVE_SYS_ENDIAN_H
+#include <sys/endian.h>
+#define bswap_32 bswap32
+#endif
+
+#if HAVE_ENDIAN_H
 #include <endian.h>
+#elif HAVE_SYS_ENDIAN_H
+#include <sys/endian.h>
+#define __BYTE_ORDER _BYTE_ORDER
+#define __BIG_ENDIAN _BIG_ENDIAN
+#define __LITTLE_ENDIAN _LITTLE_ENDIAN
+#endif
+
 #include <error.h>
 
 #include "prelink.h"
