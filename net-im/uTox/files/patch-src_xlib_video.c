--- src/xlib/video.c.orig	2016-07-26 23:53:18 UTC
+++ src/xlib/video.c
@@ -152,6 +152,9 @@ _Bool native_video_init(void *handle) {
     if(isdesktop(handle)) {
         utox_v4l_fd = -1;
 
+#ifndef volatile
+#define volatile(x) (*((volatile typeof(x)*)&x))
+#endif
         video_x = volatile(grabx);
         video_y = volatile(graby);
         video_width = volatile(grabpx);
