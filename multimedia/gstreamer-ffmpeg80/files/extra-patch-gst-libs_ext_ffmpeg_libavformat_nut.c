--- gst-libs/ext/ffmpeg/libavformat/nut.c.orig	Wed Apr 14 20:38:02 2004
+++ gst-libs/ext/ffmpeg/libavformat/nut.c	Sun Jul 11 18:14:19 2004
@@ -59,6 +59,9 @@
 #define FLAG_FULL_PTS        4
 #define FLAG_KEY_FRAME      32
 
+// UINT64_MAX isn't defined on FreeBSD 4.x borrow it from 5.x
+#define UINT64_MAX      0xffffffffffffffffULL
+
 typedef struct {
     uint8_t flags;
     uint8_t stream_id_plus1;
