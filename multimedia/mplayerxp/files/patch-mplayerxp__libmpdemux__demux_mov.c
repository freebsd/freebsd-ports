--- mplayerxp/libmpdemux/demux_mov.c.orig	Wed Sep 13 16:11:59 2006
+++ mplayerxp/libmpdemux/demux_mov.c	Sun Oct  1 21:57:58 2006
@@ -51,6 +51,10 @@
 #define char2short(x,y)	BE_16(*((uint16_t *)&(((unsigned char *)(x))[(y)])))
 #define char2int(x,y) 	BE_32(*((uint32_t *)&(((unsigned char *)(x))[(y)])))
 
+#ifndef SIZE_MAX
+#define SIZE_MAX ((size_t)-1)
+#endif
+
 typedef struct {
     unsigned int pts; // duration
     unsigned int size;
