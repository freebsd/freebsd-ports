--- src/xlib/video.c.orig	2016-05-13 18:12:01.175591000 +0300
+++ src/xlib/video.c	2016-05-13 18:12:27.944571000 +0300
@@ -152,6 +152,9 @@
     if(isdesktop(handle)) {
         utox_v4l_fd = -1;
 
+#ifndef volatile
+#define volatile(x) (*((volatile typeof(x)*)&x))
+#endif
         video_x = volatile(grabx);
         video_y = volatile(graby);
         video_width = volatile(grabpx);
