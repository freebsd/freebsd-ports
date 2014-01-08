--- ./src/jagsmntswindow.h.orig	2003-09-04 23:14:54.000000000 +0200
+++ ./src/jagsmntswindow.h	2014-01-08 10:20:11.000000000 +0100
@@ -64,4 +64,14 @@
 
 };
 
+gint close_mntswindow(GtkWidget *widget, JagsMntsWindow *me);
+gint toggle_automount(GtkWidget *widget, JagsMntsWindow *me);
+gint unmount_share(GtkWidget *widget, JagsMntsWindow *me);
+gint mnts_browse(GtkWidget *widget, JagsMntsWindow *me);
+gint change_mnt_path(GtkWidget *widget, JagsMntsWindow *me);
+void selection_made(GtkWidget *, gint, gint, GdkEventButton *, 
+			     gpointer, JagsMntsWindow *);
+gint mw_button_press(GtkWidget *widget, GdkEventButton *event, 
+			      JagsMntsWindow *me);
+
 #endif
