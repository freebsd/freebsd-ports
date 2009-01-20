--- mpeg3ifo.c.orig	2007-12-17 08:25:26.000000000 +0900
+++ mpeg3ifo.c	2008-09-11 05:39:21.000000000 +0900
@@ -1,4 +1,4 @@
-#include <byteswap.h>
+//#include <byteswap.h>
 #include <dirent.h>
 #include <fcntl.h>
 #include <stdlib.h>
@@ -10,6 +10,12 @@
 #include "mpeg3private.h"
 #include "mpeg3protos.h"
 
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#define bswap_16(x) bswap16(x)
+#define bswap_32(x) bswap32(x)
+#endif
+
 typedef struct
 {
 // Bytes relative to start of stream.
