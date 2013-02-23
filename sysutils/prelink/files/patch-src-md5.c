diff -Nur src/md5.c src/md5.c
--- src/md5.c	2013-02-19 23:54:34.000000000 +0200
+++ src/md5.c	2013-02-19 23:50:31.000000000 +0200
@@ -23,8 +23,23 @@
 #include <sys/types.h>
 #include <stdlib.h>
 #include <string.h>
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
+#if HAVE_BYTESWAP_H
 #include <byteswap.h>
+#else
+#include <sys/endian.h>
+#define bswap_32 bswap32
+#endif
+
 #include "md5.h"
 
 #if __BYTE_ORDER == __BIG_ENDIAN
