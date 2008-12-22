--- src/main.c.orig	2008-12-19 17:40:19.000000000 -0500
+++ src/main.c	2008-12-19 17:49:51.000000000 -0500
@@ -84,7 +84,7 @@
             GTK_WIN_POS_CENTER);
     gtk_window_set_resizable(GTK_WINDOW(main_window), FALSE);
     gtk_container_set_border_width(GTK_CONTAINER(main_window), 5);
-    gtk_window_set_icon(main_window,gdk_pixbuf_new_from_inline(-1, qslogo,
+    gtk_window_set_icon(GTK_WINDOW(main_window),gdk_pixbuf_new_from_inline(-1, qslogo,
         FALSE, NULL));
     
     /* main window events */
