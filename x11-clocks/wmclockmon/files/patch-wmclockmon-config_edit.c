--- wmclockmon-config/edit.c.orig	2005-04-07 09:37:43 UTC
+++ wmclockmon-config/edit.c
@@ -10,6 +10,7 @@
 #include "defines.h"
 #include "tools.h"
 #include "edit.h"
+char *newalarm;
 
 static GtkWidget *wid_status;
 static GtkWidget *wid_time;
@@ -76,7 +77,6 @@ void edit_dialog(const char *title,
                        bouton, TRUE, TRUE, 0);
     GTK_WIDGET_SET_FLAGS(GTK_WIDGET(bouton), GTK_CAN_DEFAULT);
     gtk_widget_grab_default(GTK_WIDGET(bouton));
-    gtk_widget_draw_default(GTK_WIDGET(bouton));
     gtk_widget_show(bouton);
 
     bouton = gtk_button_new_with_label("Cancel");
