
$FreeBSD$

--- codecs/video/flx/flx_codec.h.orig	Wed Nov  1 20:46:14 2000
+++ codecs/video/flx/flx_codec.h	Sun Feb  4 22:55:34 2001
@@ -33,8 +33,8 @@
 #include "config.h"
 #endif
 
-#define ReadU16(tmp1, tmp2) (Uint16)*(tmp1) = ((Uint8)*(tmp2+1)<<8)+(Uint8)*(tmp2);
-#define ReadU32(tmp1, tmp2) (Uint32)*(tmp1) = (((((((Uint8)*(tmp2+3)<<8)+((Uint8)*(tmp2+2)))<<8)+((Uint8)*(tmp2+1)))<<8)+(Uint8)*(tmp2));
+#define ReadU16(tmp1, tmp2) *(tmp1) = (Uint16)((Uint8)*(tmp2+1)<<8)+(Uint8)*(tmp2)
+#define ReadU32(tmp1, tmp2) *(tmp1) = (Uint32)(((((((Uint8)*(tmp2+3)<<8)+((Uint8)*(tmp2+2)))<<8)+((Uint8)*(tmp2+1)))<<8)+(Uint8)*(tmp2))
 
 /*
  * includes : local
@@ -52,7 +52,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
-#include <SDL/SDL.h>
+#include <SDL.h>
 
 typedef struct {
 
