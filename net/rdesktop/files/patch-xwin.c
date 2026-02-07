--- xwin.c.orig	2011-04-13 04:13:04.000000000 -0700
+++ xwin.c	2012-10-08 19:06:06.000000000 -0700
@@ -2150,4 +2150,6 @@ ui_resize_window()
 		g_backstore = bs;
 	}
+
+	ui_reset_clip();
 }
 
