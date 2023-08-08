--- wmclockmon-config/mainwindow.c.orig	2005-04-07 09:37:43 UTC
+++ wmclockmon-config/mainwindow.c
@@ -10,9 +10,9 @@
 #include "actions.h"
 
 
-static GtkWidget *edit;
-static GtkWidget *set;
-static GtkWidget *remove;
+static GtkWidget *b_edit;
+static GtkWidget *b_set;
+static GtkWidget *b_remove;
 
 static gint list_sel_cb (GtkCList *clist,
                          gint row,
@@ -20,9 +20,9 @@ static gint list_sel_cb (GtkCList *clist,
                          GdkEventButton *event,
                          void *data) {
     selected_row = row;
-    gtk_widget_set_sensitive(edit,   TRUE);
-    gtk_widget_set_sensitive(set,    TRUE);
-    gtk_widget_set_sensitive(remove, TRUE);
+    gtk_widget_set_sensitive(b_edit,   TRUE);
+    gtk_widget_set_sensitive(b_set,    TRUE);
+    gtk_widget_set_sensitive(b_remove, TRUE);
     return TRUE;
 }
 
@@ -33,9 +33,9 @@ gint list_unsel_cb (GtkCList *clist,
                            GdkEventButton *event,
                            void *data) {
     selected_row = -1;
-    gtk_widget_set_sensitive(edit,   FALSE);
-    gtk_widget_set_sensitive(set,    FALSE);
-    gtk_widget_set_sensitive(remove, FALSE);
+    gtk_widget_set_sensitive(b_edit,   FALSE);
+    gtk_widget_set_sensitive(b_set,    FALSE);
+    gtk_widget_set_sensitive(b_remove, FALSE);
     return TRUE;
 }
 
@@ -267,7 +267,7 @@ void create_mainwindow() {
     gtk_table_attach_defaults(GTK_TABLE(table), bouton, 0, 1, 1, 2);
     gtk_widget_set_sensitive(bouton, FALSE);
     gtk_widget_show(bouton);
-    edit = bouton;
+    b_edit = bouton;
 
     bouton = gtk_button_new_with_label(" Switch On/Off ");
     gtk_signal_connect(GTK_OBJECT(bouton), "clicked",
@@ -275,7 +275,7 @@ void create_mainwindow() {
     gtk_table_attach_defaults(GTK_TABLE(table), bouton, 1, 2, 1, 2);
     gtk_widget_set_sensitive(bouton, FALSE);
     gtk_widget_show(bouton);
-    set = bouton;
+    b_set = bouton;
 
     bouton = gtk_button_new_with_label(" Remove alarm ");
     gtk_signal_connect(GTK_OBJECT(bouton), "clicked",
@@ -283,7 +283,7 @@ void create_mainwindow() {
     gtk_table_attach_defaults(GTK_TABLE(table), bouton, 1, 2, 0, 1);
     gtk_widget_set_sensitive(bouton, FALSE);
     gtk_widget_show(bouton);
-    remove = bouton;
+    b_remove = bouton;
 
 
     label = gtk_label_new(" Alarms ");
@@ -312,7 +312,6 @@ void create_mainwindow() {
     gtk_box_pack_start(GTK_BOX(buttons_hbox), bouton, TRUE, TRUE, 0);
     GTK_WIDGET_SET_FLAGS(GTK_WIDGET(bouton), GTK_CAN_DEFAULT);
     gtk_widget_grab_default(GTK_WIDGET(bouton));
-    gtk_widget_draw_default(GTK_WIDGET(bouton));
     gtk_widget_show(bouton);
 
     bouton = gtk_button_new_with_label(" Cancel ");
