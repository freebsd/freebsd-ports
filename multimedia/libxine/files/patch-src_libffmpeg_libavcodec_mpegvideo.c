--- src/libffmpeg/libavcodec/mpegvideo.c.orig	Thu Sep 28 13:27:10 2006
+++ src/libffmpeg/libavcodec/mpegvideo.c	Thu Sep 28 13:27:35 2006
@@ -30,6 +30,7 @@
 #include "mpegvideo.h"
 #include "faandct.h"
 #include <limits.h>
+#include "xine_internal.h"
 
 #ifdef USE_FASTMEMCPY
 #include "fastmemcpy.h"
