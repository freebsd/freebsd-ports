
$FreeBSD$

--- shell/e-shortcuts-view-model.c	2001/09/04 16:22:15	1.1
+++ shell/e-shortcuts-view-model.c	2001/09/04 16:30:50
@@ -45,31 +45,71 @@
 };
 
 
+/* Utility functions.  */
+
+static GdkPixbuf *
+get_icon_for_item (EShortcutsViewModel *shortcuts_view_model,
+		   const EShortcutItem *item,
+		   gboolean want_mini)
+{
+	EShortcutsViewModelPrivate *priv;
+
+	priv = shortcuts_view_model->priv;
+
+	if (item->type != NULL) {
+		EStorageSet *storage_set;
+		EFolderTypeRegistry *folder_type_registry;
+
+		storage_set = e_shortcuts_get_storage_set (priv->shortcuts);
+		folder_type_registry = e_storage_set_get_folder_type_registry (storage_set);
+
+		return e_folder_type_registry_get_icon_for_type (folder_type_registry,
+								 item->type,
+								 want_mini);
+	}
+
+	g_print ("(%s is not a folder!)\n", item->name);
+
+	return NULL;
+}
+
+
 /* View initialization.  */
 
+static char *
+get_name_with_unread (const EShortcutItem *item)
+{
+	return g_strdup (item->name);
+}
+
 static void
 load_group_into_model (EShortcutsViewModel *shortcuts_view_model,
 		       int group_num)
 {
 	EShortcutsViewModelPrivate *priv;
-	EStorageSet *storage_set;
 	const GSList *shortcut_list;
 	const GSList *p;
 
 	priv = shortcuts_view_model->priv;
 
-	storage_set = e_shortcuts_get_storage_set (priv->shortcuts);
-	g_assert (storage_set != NULL);
-
 	shortcut_list = e_shortcuts_get_shortcuts_in_group (priv->shortcuts, group_num);
 	if (shortcut_list == NULL)
 		return;
 
 	for (p = shortcut_list; p != NULL; p = p->next) {
 		const EShortcutItem *item;
+		char *name_with_unread;
 
 		item = (const EShortcutItem *) p->data;
-		e_shortcut_model_add_item (E_SHORTCUT_MODEL (shortcuts_view_model), group_num, -1, item->uri, item->name);
+		name_with_unread = get_name_with_unread (item);
+
+		e_shortcut_model_add_item (E_SHORTCUT_MODEL (shortcuts_view_model),
+					   group_num, -1,
+					   item->uri,
+					   name_with_unread,
+					   get_icon_for_item (shortcuts_view_model, item, FALSE));
+
+		g_free (name_with_unread);
 	}
 }
 
@@ -153,6 +193,7 @@
 	EShortcutsViewModel *shortcuts_view_model;
 	EShortcutsViewModelPrivate *priv;
 	const EShortcutItem *shortcut_item;
+	char *name_with_unread;
 
 	shortcuts_view_model = E_SHORTCUTS_VIEW_MODEL (data);
 	priv = shortcuts_view_model->priv;
@@ -160,10 +201,14 @@
 	shortcut_item = e_shortcuts_get_shortcut (priv->shortcuts, group_num, item_num);
 	g_assert (shortcut_item != NULL);
 
+	name_with_unread = get_name_with_unread (shortcut_item);
 	e_shortcut_model_add_item (E_SHORTCUT_MODEL (shortcuts_view_model),
 				   group_num, item_num,
 				   shortcut_item->uri,
-				   shortcut_item->name);
+				   name_with_unread,
+				   get_icon_for_item (shortcuts_view_model, shortcut_item, FALSE));
+
+	g_free (name_with_unread);
 }
 
 static void
@@ -187,6 +232,7 @@
 	EShortcutsViewModel *shortcuts_view_model;
 	EShortcutsViewModelPrivate *priv;
 	const EShortcutItem *shortcut_item;
+	char *name_with_unread;
 
 	shortcuts_view_model = E_SHORTCUTS_VIEW_MODEL (data);
 	priv = shortcuts_view_model->priv;
@@ -194,10 +240,14 @@
 	shortcut_item = e_shortcuts_get_shortcut (priv->shortcuts, group_num, item_num);
 	g_assert (shortcut_item != NULL);
 
+	name_with_unread = get_name_with_unread (shortcut_item);
 	e_shortcut_model_update_item (E_SHORTCUT_MODEL (shortcuts_view_model),
 				      group_num, item_num,
 				      shortcut_item->uri,
-				      shortcut_item->name);
+				      name_with_unread,
+				      get_icon_for_item (shortcuts_view_model, shortcut_item, FALSE));
+
+	g_free (name_with_unread);
 }
 
 
@@ -213,6 +263,9 @@
 	priv = view_model->priv;
 
 	g_free (priv);
+
+	if (GTK_OBJECT_CLASS (parent_class)->destroy)
+		(* GTK_OBJECT_CLASS (parent_class)->destroy) (object);
 }
 
 
