--- src/libffmpeg/libavcodec/mpegvideo.c.orig	Sun May 30 21:24:21 2004
+++ src/libffmpeg/libavcodec/mpegvideo.c	Sat Sep 11 23:30:05 2004
@@ -3926,6 +3926,8 @@
                +sse(s, s->new_picture.data[2] + s->mb_x*8  + s->mb_y*s->uvlinesize*8,s->dest[2], w>>1, h>>1, s->uvlinesize);
 }
 
+/* xine: do not need this for decode or MPEG-1 encoding modes */
+#if 0
 static int pre_estimate_motion_thread(AVCodecContext *c, void *arg){
     MpegEncContext *s= arg;
 
@@ -3969,6 +3971,7 @@
     }
     return 0;
 }
+#endif
 
 static int mb_var_thread(AVCodecContext *c, void *arg){
     MpegEncContext *s= arg;
