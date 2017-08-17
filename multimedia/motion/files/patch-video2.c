--- video2.c.orig	2017-08-11 20:05:27 UTC
+++ video2.c
@@ -184,7 +184,7 @@ typedef struct {
 /**
  * xioctl
  */
-#ifdef __OpenBSD__
+#if defined (__OpenBSD__) || defined (__FreeBSD__)
 static int xioctl(src_v4l2_t *vid_source, unsigned long request, void *arg)
 #else
 static int xioctl(src_v4l2_t *vid_source, int request, void *arg)
