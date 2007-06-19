--- xwin.c.orig	Fri Jun  1 10:27:15 2007
+++ xwin.c	Fri Jun  1 10:28:26 2007
@@ -3219,7 +3219,7 @@
 		return;
 
 	image = XCreateImage(g_display, g_visual, g_depth, ZPixmap, 0,
-			     (char *) data, cx, cy, BitmapPad(g_display), cx * g_bpp / 8);
+			     (char *) data, cx, cy, g_bpp, 0);
 
 	if (g_ownbackstore)
 	{
