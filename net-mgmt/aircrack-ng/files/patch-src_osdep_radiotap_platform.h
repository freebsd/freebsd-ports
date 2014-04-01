--- src/osdep/radiotap/platform.h.orig	2014-04-01 19:18:03.439632822 +0200
+++ src/osdep/radiotap/platform.h	2014-04-01 19:18:19.900626663 +0200
@@ -3,7 +3,7 @@
 #ifndef _BSD_SOURCE
 #define _BSD_SOURCE
 #endif
-#include <endian.h>
+#include <machine/endian.h>
 
 #define le16_to_cpu		le16toh
 #define le32_to_cpu		le32toh
