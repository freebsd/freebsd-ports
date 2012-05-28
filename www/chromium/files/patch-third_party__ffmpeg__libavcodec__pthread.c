--- third_party/ffmpeg/libavcodec/pthread.c.orig	2012-05-20 02:54:35.986106782 +0300
+++ third_party/ffmpeg/libavcodec/pthread.c	2012-05-20 02:54:42.671106234 +0300
@@ -38,7 +38,7 @@
 #if HAVE_GETPROCESSAFFINITYMASK
 #include <windows.h>
 #endif
-#if HAVE_SYSCTL
+#if HAVE_SYSCTL && !defined(__FreeBSD__)
 #if HAVE_SYS_PARAM_H
 #include <sys/param.h>
 #endif
