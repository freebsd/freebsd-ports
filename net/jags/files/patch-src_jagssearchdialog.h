--- ./src/jagssearchdialog.h.orig	2003-09-04 23:14:54.000000000 +0200
+++ ./src/jagssearchdialog.h	2014-01-08 10:20:11.000000000 +0100
@@ -52,6 +52,13 @@
   void set_string(gchar *s);
 };
 
+gint search_clicked(GtkWidget *widget, JagsSearchDialog *me);
+gint on_close(GtkWidget *widget, JagsSearchDialog *me);
+gint onn_collapse(GtkWidget *item, JagsSearchDialog *mw);
+gint expandd_server(GtkWidget *widget, JagsSearchDialog *mw);
+gint onn_share_selected(GtkTree *tree, GtkWidget *widget, gpointer data, JagsSearchDialog *mw);
+gint check_dd_click(GtkWidget *widget, GdkEventButton *event, JagsSearchDialog *mw);
+gint button_presss (GtkWidget *widget, GdkEventButton *event, JagsSearchDialog *mw);
 
 
 #endif
