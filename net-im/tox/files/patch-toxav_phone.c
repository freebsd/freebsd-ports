--- toxav/phone.c.orig	2014-02-22 23:52:26.000000000 +0100
+++ toxav/phone.c	2014-02-23 22:31:19.000000000 +0100
@@ -67,7 +67,7 @@
 /* the quit event for SDL */
 #define FF_QUIT_EVENT (SDL_USEREVENT + 2)
 
-#ifdef __linux__
+#if defined( __linux__) || defined(__FreeBSD__)
 #define VIDEO_DRIVER "video4linux2"
 #define DEFAULT_WEBCAM "/dev/video0"
 #endif
