--- third_party/ffmpeg/libavutil/mem.c.orig	2016-05-11 19:03:23 UTC
+++ third_party/ffmpeg/libavutil/mem.c
@@ -32,7 +32,7 @@
 #include <stdint.h>
 #include <stdlib.h>
 #include <string.h>
-#if HAVE_MALLOC_H
+#if HAVE_MALLOC_H && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 
