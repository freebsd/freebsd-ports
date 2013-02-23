diff -Nur src/checksum.c src/checksum.c
--- src/checksum.c	2013-02-19 23:54:34.000000000 +0200
+++ src/checksum.c	2013-02-19 23:50:31.000000000 +0200
@@ -17,7 +17,16 @@
 
 #include <config.h>
 #include <assert.h>
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
 #include <errno.h>
 #include <error.h>
 #include <fcntl.h>
