--- libmpeg3/mpeg3ifo.c.orig	Mon Feb 12 22:35:19 2001
+++ libmpeg3/mpeg3ifo.c	Mon Nov  1 09:41:06 2004
@@ -1,4 +1,3 @@
-#include <byteswap.h>
 #include <dirent.h>
 #include <fcntl.h>
 #include <stdlib.h>
@@ -69,6 +68,13 @@
 #define OFF_VMG_MENU_PGCI mpeg3_ifo_get4bytes (ifo->data[ID_MAT] + 0xC8)
 #define OFF_VMG_TMT mpeg3_ifo_get4bytes (ifo->data[ID_MAT] + 0xD0)
 
+#define bswap_16(x) ((((x) << 8) & 0xff00) | \
+                     (((x) >> 8) & 0x00ff))
+
+#define bswap_32(x) ((((x) << 24) & 0xff000000) | \
+                     (((x) <<  8) & 0x00ff0000) | \
+                     (((x) >>  8) & 0x0000ff00) | \
+                     (((x) >> 24) & 0x000000ff))
 
 inline u_int mpeg3_ifo_get4bytes(u_char *buf)
 {
