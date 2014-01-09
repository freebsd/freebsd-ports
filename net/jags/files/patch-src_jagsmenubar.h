--- ./src/jagsmenubar.h.orig	2003-09-04 23:14:54.000000000 +0200
+++ ./src/jagsmenubar.h	2014-01-08 10:20:11.000000000 +0100
@@ -105,4 +105,23 @@
 
 };
 
+gint mount_and_browse(GtkMenuItem *item, JagsMenuBar *jmb);
+gint browse(GtkMenuItem *item, JagsMenuBar *jmb);
+gint mount(GtkMenuItem *item, JagsMenuBar *jmb);
+gint mount_with(GtkMenuItem *item, JagsMenuBar *jmb);
+gint mount_with_command(GtkMenuItem *item, JagsMenuBar *jmb);
+gint preferences(GtkMenuItem *item, JagsConfig *conf);
+gint about(GtkMenuItem *item, JagsMenuBar *jmb);
+gint my_search(GtkMenuItem *item, JagsMenuBar *jmb);
+gint umount(GtkMenuItem *item, JagsMenuBar *jmb);
+gint mnts_window(GtkMenuItem *item, JagsMenuBar *jmb);
+gint bookmark_menu(GtkMenuItem *item, JagsMenuBar *jmb);
+gint bookmark_add(GtkMenuItem *item, JagsMenuBar *jmb);
+gint bookmark_edit(GtkMenuItem *item, JagsMenuBar *jmb);
+gint bookmark_selected(GtkMenuItem *item, JagsMenuBar *jmb);
+gint bookmarks_add_edit(GtkMenuItem *item, JagsMenuBar *jmb);
+void bookmarks_radio_local_toggle (GtkWidget *widget, gpointer data);
+gint bookmarks_edit_add_close(GtkWidget *widget, gpointer data);
+gint bookmarks_edit_add_ok(GtkWidget *widget, gpointer data);
+
 #endif
