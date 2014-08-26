--- ./third_party/ffmpeg/libavutil/mem.c.orig	2014-08-20 21:04:28.000000000 +0200
+++ ./third_party/ffmpeg/libavutil/mem.c	2014-08-22 15:06:26.000000000 +0200
@@ -32,7 +32,7 @@
 #include <stdint.h>
 #include <stdlib.h>
 #include <string.h>
-#if HAVE_MALLOC_H
+#if HAVE_MALLOC_H && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 
