diff -Nur src/mdebug.c src/mdebug.c
--- src/mdebug.c	2013-02-19 23:54:34.000000000 +0200
+++ src/mdebug.c	2013-02-20 00:00:05.000000000 +0200
@@ -17,8 +17,24 @@
 
 #include <config.h>
 #include <assert.h>
+
+#if HAVE_BYTESWAP_H
 #include <byteswap.h>
+#elif HAVE_SYS_ENDIAN_H
+#include <sys/endian.h>
+#define bswap_32 bswap32
+#define bswap_64 bswap64
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
 #include <stddef.h>
 
