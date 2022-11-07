--- wmmaiload-config/mainwindow.c.orig	2009-02-23 02:58:00 UTC
+++ wmmaiload-config/mainwindow.c
@@ -12,7 +12,7 @@
 
 static GtkWidget *b_edit;
 static GtkWidget *b_set;
-static GtkWidget *b_remove;
+static GtkWidget *b_rm;
 
 static gint list_sel_cb (GtkCList *clist,
                          gint row,
@@ -23,7 +23,7 @@ static gint list_sel_cb (GtkCList *clist,
         selected_row = row;
         gtk_widget_set_sensitive(b_edit, TRUE);
         gtk_widget_set_sensitive(b_set, TRUE);
-        gtk_widget_set_sensitive(b_remove, TRUE);
+        gtk_widget_set_sensitive(b_rm, TRUE);
         return TRUE;
 }
 
@@ -37,7 +37,7 @@ gint list_unsel_cb (GtkCList *clist,
         selected_row = -1;
         gtk_widget_set_sensitive(b_edit, FALSE);
         gtk_widget_set_sensitive(b_set, FALSE);
-        gtk_widget_set_sensitive(b_remove, FALSE);
+        gtk_widget_set_sensitive(b_rm, FALSE);
         return TRUE;
 }
 
@@ -66,7 +66,7 @@ void create_mainwindow()
 
         /*** FENÊTRE PRINCIPALE ***/
         application = gtk_window_new(GTK_WINDOW_TOPLEVEL);
-        gtk_window_set_title(GTK_WINDOW(application), PACKAGE"-config");
+        gtk_window_set_title(GTK_WINDOW(application), PACKAGE);
         /*-- Connexion aux signaux --*/
         gtk_signal_connect(GTK_OBJECT(application), "delete_event",
                            GTK_SIGNAL_FUNC(quit_app), NULL);
@@ -246,7 +246,7 @@ void create_mainwindow()
         gtk_table_attach_defaults(GTK_TABLE(table), bouton, 2, 3, 0, 1);
         gtk_widget_set_sensitive(bouton, FALSE);
         gtk_widget_show(bouton);
-        b_remove = bouton;
+        b_rm = bouton;
 
         /*--- Frame 5 ---*/
         frame = gtk_frame_new(NULL);
