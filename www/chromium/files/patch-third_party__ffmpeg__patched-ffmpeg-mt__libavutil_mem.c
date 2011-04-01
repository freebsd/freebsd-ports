--- third_party/ffmpeg/patched-ffmpeg-mt/libavutil/mem.c.orig	2011-03-25 14:43:09.000000000 +0200
+++ third_party/ffmpeg/patched-ffmpeg-mt/libavutil/mem.c	2011-03-25 14:43:21.000000000 +0200
@@ -30,7 +30,7 @@
 #include <stdlib.h>
 #include <string.h>
 #if HAVE_MALLOC_H
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 
 #include "avutil.h"
