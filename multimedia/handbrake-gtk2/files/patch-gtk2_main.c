--- gtk2/main.c.orig	Sat Nov 20 19:20:18 2004
+++ gtk2/main.c	Sat Nov 20 19:21:02 2004
@@ -85,6 +85,7 @@

     /* build dvd list */
     items = g_list_append (items, "" );
+    items = g_list_append (items, "/dev/%%DVD_DEVICE%%" );
     items = g_list_append (items, "/dev/dvd" );
     gtk_combo_set_popdown_strings( GTK_COMBO(lookup_widget( hb_win_main, "combo1") ), items );

