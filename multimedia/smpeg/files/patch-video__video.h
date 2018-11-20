--- video/video.h.orig	2001-02-10 07:36:42 UTC
+++ video/video.h
@@ -432,7 +432,7 @@ extern unsigned int cacheMiss[8][8];
 #undef  LITTLE_ENDIAN_ARCHITECTURE
 #define BIG_ENDIAN_ARCHITECTURE 1
 #else
-#include <endian.h>
+#include <sys/endian.h>
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 #undef  BIG_ENDIAN_ARCHITECTURE
 #define LITTLE_ENDIAN_ARCHITECTURE 1
