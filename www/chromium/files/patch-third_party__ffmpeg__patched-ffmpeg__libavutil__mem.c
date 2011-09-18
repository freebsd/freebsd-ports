--- third_party/ffmpeg/patched-ffmpeg/libavutil/mem.c.orig	2011-09-11 11:03:30.000000000 +0300
+++ third_party/ffmpeg/patched-ffmpeg/libavutil/mem.c	2011-09-12 23:49:42.000000000 +0300
@@ -31,7 +31,7 @@
 #include <limits.h>
 #include <stdlib.h>
 #include <string.h>
-#if HAVE_MALLOC_H
+#if HAVE_MALLOC_H && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 
