--- core/Scale.c.orig	Mon Nov 22 21:59:25 2004
+++ core/Scale.c	Mon Nov 22 21:59:48 2004
@@ -6,7 +6,7 @@

 #include "HBInternal.h"

-#include "ffmpeg/avcodec.h"
+#include "avcodec.h"

 struct HBWork
 {
@@ -52,7 +52,8 @@
         img_resample_full_init( title->outWidth, title->outHeight,
                                 title->inWidth,  title->inHeight,
                                 title->topCrop,  title->bottomCrop,
-                                title->leftCrop, title->rightCrop );
+                                title->leftCrop, title->rightCrop,
+                                0,0,0,0 );

     return w;
 }
