--- core/HandBrake.c.orig	Wed May 26 05:51:32 2004
+++ core/HandBrake.c	Sun Dec 19 11:02:32 2004
@@ -277,7 +277,8 @@
         img_resample_full_init( t->outWidth, t->outHeight,
                                 t->inWidth, t->inHeight,
                                 t->topCrop, t->bottomCrop,
-                                t->leftCrop, t->rightCrop );
+                                t->leftCrop, t->rightCrop,
+                                0,0,0,0 );
     if( t->deinterlace )
     {
         avpicture_deinterlace( &pic2, &pic1, PIX_FMT_YUV420P,
@@ -709,7 +710,7 @@
     get_system_info( &info );
     CPUCount = info.cpu_count;

-#elif defined( HB_MACOSX )
+#elif defined( HB_MACOSX ) || defined( HB_FREEBSD )
     FILE * info;
     char   buffer[256];

