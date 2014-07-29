--- video/video.h.orig	Sun Feb  8 23:39:25 2004
+++ video/video.h	Sun Feb  8 23:39:36 2004
@@ -432,7 +432,7 @@
 #undef  LITTLE_ENDIAN_ARCHITECTURE
 #define BIG_ENDIAN_ARCHITECTURE 1
 #else
-#include <endian.h>
+#include <sys/endian.h>
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 #undef  BIG_ENDIAN_ARCHITECTURE
 #define LITTLE_ENDIAN_ARCHITECTURE 1
