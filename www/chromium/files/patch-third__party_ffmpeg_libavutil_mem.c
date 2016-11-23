--- third_party/ffmpeg/libavutil/mem.c.orig	2016-08-03 22:03:29.000000000 +0300
+++ third_party/ffmpeg/libavutil/mem.c	2016-10-11 02:40:34.765488000 +0300
@@ -32,9 +32,6 @@
 #include <stdint.h>
 #include <stdlib.h>
 #include <string.h>
-#if HAVE_MALLOC_H
-#include <malloc.h>
-#endif
 
 #include "avassert.h"
 #include "avutil.h"
