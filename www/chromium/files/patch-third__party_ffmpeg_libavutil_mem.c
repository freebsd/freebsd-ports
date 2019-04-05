--- third_party/ffmpeg/libavutil/mem.c.orig	2019-03-11 22:08:00 UTC
+++ third_party/ffmpeg/libavutil/mem.c
@@ -32,9 +32,6 @@
 #include <stdint.h>
 #include <stdlib.h>
 #include <string.h>
-#if HAVE_MALLOC_H
-#include <malloc.h>
-#endif
 
 #include "avassert.h"
 #include "avutil.h"
