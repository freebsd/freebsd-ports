--- ffmpeg/libavcodec/mem.c.orig	Thu Jan 30 19:58:35 2003
+++ ffmpeg/libavcodec/mem.c	Thu Jan 30 19:58:45 2003
@@ -18,7 +18,7 @@
  */
 #include "avcodec.h"
 #ifdef HAVE_MALLOC_H
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 
 /* you can redefine av_malloc and av_free in your project to use your
