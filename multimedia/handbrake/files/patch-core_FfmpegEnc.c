--- core/FfmpegEnc.c.orig	Sun Dec 19 11:16:49 2004
+++ core/FfmpegEnc.c	Sun Dec 19 11:16:58 2004
@@ -132,7 +132,7 @@
     }

     HBBufferClose( &scaledBuffer );
-    free( frame );
+    av_free( frame );

     return 1;
 }
