--- core/Scale.c.orig	Wed May 26 05:51:32 2004
+++ core/Scale.c	Sun Dec 19 11:02:44 2004
@@ -52,7 +52,8 @@
         img_resample_full_init( title->outWidth, title->outHeight,
                                 title->inWidth,  title->inHeight,
                                 title->topCrop,  title->bottomCrop,
-                                title->leftCrop, title->rightCrop );
+                                title->leftCrop, title->rightCrop,
+                                0,0,0,0 );

     return w;
 }
