--- wmclockmon-config/dialogs.c.orig	2005-04-07 09:37:43 UTC
+++ wmclockmon-config/dialogs.c
@@ -38,7 +38,6 @@ void ync_dialog(const char *title, const char *text, v
                        bouton, TRUE, TRUE, 0);
     GTK_WIDGET_SET_FLAGS(GTK_WIDGET(bouton), GTK_CAN_DEFAULT);
     gtk_widget_grab_default(GTK_WIDGET(bouton));
-    gtk_widget_draw_default(GTK_WIDGET(bouton));
     gtk_widget_show(bouton);
 
     bouton = gtk_button_new_with_label("No");
@@ -96,7 +95,6 @@ void ok_dialog(const char *title, const char *text) {
                        bouton, TRUE, TRUE, 0);
     GTK_WIDGET_SET_FLAGS(GTK_WIDGET(bouton), GTK_CAN_DEFAULT);
     gtk_widget_grab_default(GTK_WIDGET(bouton));
-    gtk_widget_draw_default(GTK_WIDGET(bouton));
     gtk_widget_show(bouton);
 
     gtk_container_set_border_width(GTK_CONTAINER
