Right click context menu with wrong icon (bug #10652)

--- thunar/thunar-templates-action.c.orig	2013-12-18 23:41:57 UTC
+++ thunar/thunar-templates-action.c
@@ -477,7 +477,7 @@ thunar_templates_action_load_finished (T
       gtk_widget_show (item);
 
       /* add the icon for the emtpy file item */
-      image = gtk_image_new_from_stock (GTK_STOCK_NEW, GTK_ICON_SIZE_MENU);
+      image = gtk_image_new_from_stock (GTK_STOCK_FILE, GTK_ICON_SIZE_MENU);
       gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (item), image);
     }
 
@@ -542,6 +542,7 @@ thunar_templates_action_new (const gchar
                        "hide-if-empty", FALSE,
                        "label", label,
                        "name", name,
+                       "icon-name", "document-new",
                        NULL);
 }
 
