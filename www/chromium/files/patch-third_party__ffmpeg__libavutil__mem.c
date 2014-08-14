--- ./third_party/ffmpeg/libavutil/mem.c.orig	2014-08-12 21:03:23.000000000 +0200
+++ ./third_party/ffmpeg/libavutil/mem.c	2014-08-13 09:56:58.000000000 +0200
@@ -32,7 +32,7 @@
 #include <stdint.h>
 #include <stdlib.h>
 #include <string.h>
-#if HAVE_MALLOC_H
+#if HAVE_MALLOC_H && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 
