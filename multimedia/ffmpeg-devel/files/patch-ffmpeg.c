--- ffmpeg.c.orig	Mon Aug 13 18:23:57 2001
+++ ffmpeg.c	Tue Sep 25 14:47:58 2001
@@ -35,6 +35,7 @@
 
 #include "avformat.h"
 
+#define INT64_C(x) x##LL
 #define MAXINT64 INT64_C(0x7fffffffffffffff)
 
 typedef struct {
