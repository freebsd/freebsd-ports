--- gnome/glayout.c.orig	Sun Aug 11 18:35:37 2002
+++ gnome/glayout.c	Sun Aug 11 18:37:47 2002
@@ -625,13 +625,13 @@
 
 	shell = gnome_panel_new_menu[0].widget->parent;
 
-	file = gnome_unconditional_datadir_file ("mc/templates");
+	file = gnome_unconditional_datadir_file ("gnome/mc/templates");
 
 	child_list = gtk_container_children (GTK_CONTAINER (shell));
 	pos = g_list_length (child_list);
 	pos = create_new_menu_from (file, shell, pos);
 
-	file2 = gnome_datadir_file ("mc/templates");
+	file2 = gnome_datadir_file ("gnome/mc/templates");
 	if (file2 != NULL){
 		if (strcmp (file, file2) != 0)
 			create_new_menu_from (file2, shell, pos);
