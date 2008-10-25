--- src/xine-engine/buffer.h.orig	2008-07-16 17:01:56.000000000 -0400
+++ src/xine-engine/buffer.h	2008-10-23 14:25:45.000000000 -0400
@@ -676,7 +676,7 @@
 /* convert xine_waveformatex struct from little endian */
 void _x_waveformatex_le2me( xine_waveformatex *wavex ) XINE_PROTECTED;
 
-static inline _x_is_fourcc(void *ptr, void *tag) {
+static inline int _x_is_fourcc(void *ptr, void *tag) {
   return memcmp(ptr, tag, 4) == 0;
 }
 
