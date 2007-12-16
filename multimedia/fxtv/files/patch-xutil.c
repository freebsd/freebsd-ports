--- ./xutil.c.orig	Fri Nov  5 09:38:54 1999
+++ ./xutil.c	Tue Oct  9 03:41:54 2007
@@ -1500,8 +1500,10 @@
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
