--- ./capplets/common/theme-thumbnail.c.orig	2016-01-09 18:24:24.817763000 +0100
+++ ./capplets/common/theme-thumbnail.c	2016-01-09 18:25:23.640259000 +0100
@@ -145,9 +145,7 @@ static GdkPixmap* draw_window_on_pixbuf(
 
 	gtk_widget_hide(widget);
 
-#if GTK_CHECK_VERSION (3, 0, 0)
-	return pixbuf;
-#else
+#if !GTK_CHECK_VERSION (3, 0, 0)
 	return pixmap;
 #endif
 }
