--- beep/playlist_list.c.orig	Sat Feb  7 17:53:46 2004
+++ beep/playlist_list.c	Sat Feb  7 17:54:59 2004
@@ -372,6 +372,7 @@
     gint i, tw, max_first;
     guint padding;
     guint max_time_len = 0;
+	gchar **frags;
 
     gc = pl->pl_widget.gc;
     width = pl->pl_widget.width;
@@ -507,7 +508,7 @@
 
 
 
-	    gchar **frags = g_strsplit(tail, ":", 0);
+	    frags = g_strsplit(tail, ":", 0);
 
 	    layout =
 		gtk_widget_create_pango_layout(GTK_WIDGET(playlistwin),
