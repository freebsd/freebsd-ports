
$FreeBSD$

--- shell/e-shortcuts-view.c	2001/09/04 16:40:47	1.1
+++ shell/e-shortcuts-view.c	2001/09/04 16:44:17
@@ -86,47 +86,6 @@
 	return colon + 1;
 }
 
-/* Icon callback for the shortcut bar.  */
-static GdkPixbuf *
-icon_callback (EShortcutBar *shortcut_bar,
-	       const char *uri,
-	       gpointer data)
-{
-	EFolderTypeRegistry *folder_type_registry;
-	EShortcuts *shortcuts;
-	EStorageSet *storage_set;
-	EFolder *folder;
-	GdkPixbuf *pixbuf;
-	const char *type;
-
-	shortcuts = E_SHORTCUTS (data);
-
-	storage_set = e_shortcuts_get_storage_set (shortcuts);
-	folder_type_registry = e_storage_set_get_folder_type_registry (storage_set);
-
-	if (strcmp ("evolution:/My Evolution", uri) == 0) {
-		type = "My Evolution";
-	} else {
-		folder = e_storage_set_get_folder (storage_set,
-						   get_storage_set_path_from_uri (uri));
-
-		if (folder == NULL)
-			return NULL;
-		
-		type = e_folder_get_type_string (folder);
-		if (type == NULL)
-			return NULL;
-	}
-
-	/* FIXME mini icons?  */
-	pixbuf = e_folder_type_registry_get_icon_for_type (folder_type_registry, type, FALSE);
-
-	if (pixbuf != NULL)
-		gdk_pixbuf_ref (pixbuf);
-
-	return pixbuf;
-}
-
 
 static void
 show_new_group_dialog (EShortcutsView *view)
@@ -659,9 +618,6 @@
 
 	priv->shortcuts = shortcuts;
 	gtk_object_ref (GTK_OBJECT (priv->shortcuts));
-
-	e_shortcut_bar_set_icon_callback (E_SHORTCUT_BAR (shortcuts_view), icon_callback,
-					  shortcuts);
 
 	e_shortcut_bar_set_model (E_SHORTCUT_BAR (shortcuts_view),
 				  E_SHORTCUT_MODEL (e_shortcuts_view_model_new (shortcuts)));
