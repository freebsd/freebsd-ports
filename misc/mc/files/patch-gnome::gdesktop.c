--- gnome/gdesktop.c.orig	Sun Aug 11 18:35:31 2002
+++ gnome/gdesktop.c	Sun Aug 11 18:37:59 2002
@@ -3036,9 +3036,9 @@
 	strip_tearoff_menu_item (desktop_arrange_icons_items);
 	i = strip_tearoff_menu_item (gnome_panel_new_menu);
 	shell = gnome_panel_new_menu[0].widget->parent;
-	file = gnome_unconditional_datadir_file ("mc/templates");
+	file = gnome_unconditional_datadir_file ("gnome/mc/templates");
 	i = create_new_menu_from (file, shell, i);
-	file2 = gnome_datadir_file ("mc/templates");
+	file2 = gnome_datadir_file ("gnome/mc/templates");
 	if (file2 != NULL){
 		if (strcmp (file, file2) != 0)
 			create_new_menu_from (file2, shell, i);
