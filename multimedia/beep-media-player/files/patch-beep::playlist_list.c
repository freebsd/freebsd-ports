--- beep/playlist_list.c.orig	Fri Nov 14 05:24:54 2003
+++ beep/playlist_list.c	Fri Nov 14 05:28:24 2003
@@ -292,6 +292,8 @@
 	int len;
 	int pix_len;
 	char *tmp;
+	guint padding, plist_length_int;
+	PangoLayout * layout;
 
 	if (cfg.convert_underscore)
 		while ((tmp = strchr(text, '_')) != NULL)
@@ -318,9 +320,6 @@
 		pix_len = (width_approx_letters * len);
 	}
 
-
-	guint padding, plist_length_int;
-	PangoLayout * layout;
 	if (cfg.show_numbers_in_pl) {
 
 
@@ -442,12 +441,13 @@
 		{
 			int x, y;
 			gchar * tail;
-
+			guint t_width;
+			guint len_tail;
+			guint len;
+			
 			tail = g_strdup_printf("%s%s",qstr,length);
 
 			if (strlen(tail) > max_time_len) max_time_len = strlen(tail);
-			guint t_width;
-			guint len_tail;
 	
 			/* FIXME: This is just an approximate alignment, maybe
 			        something still fast, but exact could be done */
@@ -485,7 +485,7 @@
 			else
 				gdk_gc_set_foreground(gc, get_skin_color(SKIN_PLEDIT_NORMAL));
 
-			guint len = strlen(tail);
+			len = strlen(tail);
 
 			layout = gtk_widget_create_pango_layout(GTK_WIDGET(playlistwin),tail);
 			pango_layout_set_font_description (layout, playlist_list_font); 
