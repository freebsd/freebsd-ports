Right click context menu with wrong icon (bug #10652)

--- thunar/thunar-tree-view.c.orig	2013-12-18 23:41:57 UTC
+++ thunar/thunar-tree-view.c
@@ -1093,6 +1093,7 @@ thunar_tree_view_context_menu (ThunarTre
   GtkWidget    *menu;
   GtkWidget    *item;
   GtkWidget    *window;
+  GIcon        *icon;
   GList        *providers, *lp;
   GList        *actions = NULL, *tmp;
 
@@ -1201,6 +1202,12 @@ thunar_tree_view_context_menu (ThunarTre
       g_signal_connect_swapped (G_OBJECT (item), "activate", G_CALLBACK (thunar_tree_view_action_create_folder), view);
       gtk_menu_shell_append (GTK_MENU_SHELL (menu), item);
       gtk_widget_show (item);
+      
+      /* set the stock icon */
+      icon = g_themed_icon_new ("folder-new");
+      image = gtk_image_new_from_gicon (icon, GTK_ICON_SIZE_MENU);
+      gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (item), image);
+      g_object_unref (icon);
 
       /* append a separator item */
       item = gtk_separator_menu_item_new ();
