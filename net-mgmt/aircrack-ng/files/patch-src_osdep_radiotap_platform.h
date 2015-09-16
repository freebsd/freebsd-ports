--- src/osdep/radiotap/platform.h.orig	2014-03-22 20:26:59 UTC
+++ src/osdep/radiotap/platform.h
@@ -3,7 +3,7 @@
 #ifndef _BSD_SOURCE
 #define _BSD_SOURCE
 #endif
-#include <endian.h>
+#include <machine/endian.h>
 
 #define le16_to_cpu		le16toh
 #define le32_to_cpu		le32toh
