--- window.c.orig	Sun Jan  7 16:08:02 2007
+++ window.c	Wed Jan 17 14:26:01 2007
@@ -73,6 +73,8 @@
     guint accelKey;
     GdkModifierType accelModifier;
     GClosure *closure = NULL;
+    GtkWidget* submenu;
+    GtkWidget* rootSubmenu;
     
     /* KEYBOARD accelerators */
     accelGroup = gtk_accel_group_new();
@@ -222,9 +224,6 @@
     gtk_widget_show(menuItem);
     g_signal_connect(G_OBJECT(menuItem), "activate",
                      G_CALLBACK(deleteBootRecordCbk), NULL);
-    
-    GtkWidget* submenu;
-    GtkWidget* rootSubmenu;
     
     rootSubmenu = gtk_image_menu_item_new_from_stock(GTK_STOCK_ADD, NULL);
     gtk_menu_shell_append(GTK_MENU_SHELL(menu), rootSubmenu);
