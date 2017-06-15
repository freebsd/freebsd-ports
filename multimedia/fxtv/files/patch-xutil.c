--- xutil.c.orig	1999-11-05 00:38:54 UTC
+++ xutil.c
@@ -1500,8 +1500,10 @@ void XUTILDetermineFrameBufferVisual( Di
     /**********************************************************************/
 
     vinfo_pref.screen = screen;
-    visual = XGetVisualInfo( display, VisualScreenMask, &vinfo_pref, 
-                             &num_visuals );
+    vinfo_pref.depth = DefaultDepth( display, screen );
+    visual = XGetVisualInfo( display,
+                             VisualScreenMask | VisualDepthMask,
+                             &vinfo_pref, &num_visuals );
     if ( num_visuals == 0 ) {
         fprintf( stderr, "XGetVisualInfo() says no visuals available!\n" );
         exit(1);
