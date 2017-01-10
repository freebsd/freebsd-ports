--- src/xlib/video.c.orig	2016-12-21 09:12:44 UTC
+++ src/xlib/video.c
@@ -144,6 +144,9 @@ bool native_video_init(void *handle) {
     if (isdesktop(handle)) {
         utox_v4l_fd = -1;
 
+#ifndef volatile
+#define volatile(x) (*((volatile typeof(x)*)&x))
+#endif
         video_x      = volatile(grabx);
         video_y      = volatile(graby);
         video_width  = volatile(grabpx);
