--- src/gvnc.c.orig	2007-12-16 13:59:46.000000000 -0500
+++ src/gvnc.c	2007-12-16 14:01:54.000000000 -0500
@@ -16,7 +16,7 @@
 
 #include <netdb.h>
 #include <string.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <errno.h>
@@ -26,7 +26,19 @@
 #include <string.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+
+#define __BYTE_ORDER            _BYTE_ORDER
+#define __LITTLE_ENDIAN         _LITTLE_ENDIAN
+#define __BIG_ENDIAN            _BIG_ENDIAN
+
+#define bswap_16                bswap16
+#define bswap_32                bswap32
+#define bswap_64                bswap64
+#else
 #include <endian.h>
+#endif
 
 #include "coroutine.h"
 #include "d3des.h"
