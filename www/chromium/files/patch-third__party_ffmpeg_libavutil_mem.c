--- third_party/ffmpeg/libavutil/mem.c.orig	2021-09-24 04:28:06 UTC
+++ third_party/ffmpeg/libavutil/mem.c
@@ -33,9 +33,6 @@
 #include <stdlib.h>
 #include <stdatomic.h>
 #include <string.h>
-#if HAVE_MALLOC_H
-#include <malloc.h>
-#endif
 
 #include "avutil.h"
 #include "common.h"
