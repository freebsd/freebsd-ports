--- modules/codec/mpeg_video/parser.c.orig	Mon Jun 30 18:15:14 2003
+++ modules/codec/mpeg_video/parser.c	Mon Jun 30 18:16:37 2003
@@ -143,7 +143,7 @@
     {
         free( p_vpar );
         return( -1 );
-    )
+    }
 
     /*
      * Main loop - it is not executed if an error occured during
