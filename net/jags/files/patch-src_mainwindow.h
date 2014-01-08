--- ./src/mainwindow.h.orig	2003-09-04 23:14:54.000000000 +0200
+++ ./src/mainwindow.h	2014-01-08 10:20:11.000000000 +0100
@@ -59,5 +59,12 @@
 
 gint on_collapse(GtkWidget *item, MainWindow *mw);
 gint check_server_click(GtkWidget *widget, GdkEventButton *event, MainWindow *mw);
+gint expand_network(GtkWidget *widget, MainWindow *mw);
+gint expand_workgroup(GtkWidget *widget, MainWindow *mw);
+gint expand_server(GtkWidget *widget, GtkTree *root_tree);
+gint on_share_selected(GtkTree *tree, GtkWidget *widget, gpointer data);
+gint on_workgroup_selected(GtkTree *tree, GtkWidget *widget, GtkTree *root_tree);
+gint check_d_click(GtkWidget *widget, GdkEventButton *event, MainWindow *mw);
+gint button_press(GtkWidget *, GdkEventButton *, MainWindow *mw);
 
 #endif
