--- src/device-info.c.orig	2008-04-16 05:17:47.000000000 +1000
+++ src/device-info.c	2008-06-11 20:59:44.000000000 +1000
@@ -356,12 +356,12 @@
   }
 
   gint response;
-  guint32 index, item;
+  guint32 item;
   gboolean active, result;
   guint id;
   gchar *name = NULL;
+  GtkListStore *store = NULL;
   GtkTreeIter iter;
-  GtkTreeModel *model;
   GtkCellRenderer *renderer;
   GtkTreeViewColumn *column;
   GtkWidget *device_info_dialog = priv->dialog;
@@ -369,7 +369,6 @@
   GtkWidget *create_pship_dialog = glade_xml_get_widget (xml, "create_partnership_dialog"); 
   GtkWidget *pship_name_entry = glade_xml_get_widget (xml, "pship_name_entry");
   GtkWidget *sync_items_listview = glade_xml_get_widget (xml, "sync_items_listview");
-  GtkTreeSelection *selection = gtk_tree_view_get_selection (GTK_TREE_VIEW (sync_items_listview));
   GArray *sync_items_required = NULL;
   GHashTable *sync_items = NULL;
   GError *error = NULL;
@@ -433,10 +432,10 @@
     goto exit;
   }
 
-  GtkListStore *store = gtk_list_store_new (SYNCITEM_N_COLUMNS,
-                                            G_TYPE_INT,     /* index */
-                                            G_TYPE_BOOLEAN,     /* selected */
-                                            G_TYPE_STRING); /* program name */
+  store = gtk_list_store_new (SYNCITEM_N_COLUMNS,
+			      G_TYPE_INT,     /* index */
+			      G_TYPE_BOOLEAN,     /* selected */
+			      G_TYPE_STRING); /* program name */
 
   g_hash_table_foreach(sync_items, setup_sync_item_store, store);
   g_hash_table_destroy(sync_items);
@@ -529,6 +528,256 @@
 }
 
 
+#if GLIB_MINOR_VERSION < 14
+static void
+get_sync_item_keys(gpointer key,
+		   gpointer value,
+		   gpointer user_data)
+{
+  *(GList **)user_data = g_list_append(*(GList **)user_data, key);
+}
+#endif
+
+
+static gboolean
+check_delete_orphans(WmDeviceInfo *self, guint id, gchar *guid)
+{
+  WmDeviceInfoPrivate *priv = WM_DEVICE_INFO_GET_PRIVATE (self);
+  if (priv->disposed) {
+    g_warning("%s: Disposed object passed", G_STRFUNC);
+    return FALSE;
+  }
+
+  GError *error = NULL;
+  DBusGConnection *dbus_connection = NULL;
+  DBusGProxy *sync_engine_proxy = NULL;
+  gboolean result = FALSE;
+
+  GPtrArray* partnership_list = NULL;
+  GValueArray *partnership = NULL;
+  GHashTable *sync_items = NULL;
+  gboolean show_extra_warning;
+  GArray *orphaned_items = NULL;
+  GArray *sync_items_active = NULL;
+  GHashTable *pship_connections = NULL;
+  GList *item_keys = NULL, *tmp_list = NULL;
+  guint *sync_item_key = NULL;
+  guint index;
+
+  dbus_connection = dbus_g_bus_get (DBUS_BUS_SESSION, &error);
+  if (dbus_connection == NULL) {
+    g_critical("%s: Failed to open connection to bus: %s", G_STRFUNC, error->message);
+
+    GtkWidget *failed_dialog = gtk_message_dialog_new(GTK_WINDOW(priv->dialog),
+						      GTK_DIALOG_DESTROY_WITH_PARENT,
+						      GTK_MESSAGE_WARNING,
+						      GTK_BUTTONS_OK,
+						      "Deletion of partnership was unsuccessful: %s",
+						      error->message);
+
+    gtk_dialog_run(GTK_DIALOG(failed_dialog));
+    gtk_widget_destroy (failed_dialog);
+
+    g_error_free (error);
+    goto exit;
+  }
+
+  sync_engine_proxy = dbus_g_proxy_new_for_name (dbus_connection,
+						 "org.synce.SyncEngine",
+						 "/org/synce/SyncEngine",
+						 "org.synce.SyncEngine");
+  if (sync_engine_proxy == NULL) {
+    g_critical("%s: Failed to create proxy to sync engine", G_STRFUNC);
+
+    GtkWidget *failed_dialog = gtk_message_dialog_new(GTK_WINDOW(priv->dialog),
+						      GTK_DIALOG_DESTROY_WITH_PARENT,
+						      GTK_MESSAGE_WARNING,
+						      GTK_BUTTONS_OK,
+						      "Deletion of partnership was unsuccessful: Failed to connect to SyncEngine");
+
+    gtk_dialog_run(GTK_DIALOG(failed_dialog));
+    gtk_widget_destroy (failed_dialog);
+
+    goto exit;
+  }
+
+  result = org_synce_syncengine_get_partnerships (sync_engine_proxy, &partnership_list, &error);
+  if (!result) {
+    g_critical("%s: Error getting partnership list from sync-engine: %s", G_STRFUNC, error->message);
+    
+    GtkWidget *failed_dialog = gtk_message_dialog_new(GTK_WINDOW(priv->dialog),
+						      GTK_DIALOG_DESTROY_WITH_PARENT,
+						      GTK_MESSAGE_WARNING,
+						      GTK_BUTTONS_OK,
+						      "Failed to retrieve partnership information: %s",
+						      error->message);
+
+    gtk_dialog_run(GTK_DIALOG(failed_dialog));
+    gtk_widget_destroy (failed_dialog);
+
+    g_error_free(error);
+    goto exit;
+  }
+
+  result = org_synce_syncengine_get_item_types(sync_engine_proxy, &sync_items, &error);
+  if (!result) {
+    g_critical("%s: Error fetching sync item list: %s", G_STRFUNC, error->message);
+
+    GtkWidget *failed_dialog = gtk_message_dialog_new(GTK_WINDOW(priv->dialog),
+						      GTK_DIALOG_DESTROY_WITH_PARENT,
+						      GTK_MESSAGE_WARNING,
+						      GTK_BUTTONS_OK,
+						      "Failed to retrieve partnership information: %s",
+						      error->message);
+
+    gtk_dialog_run(GTK_DIALOG(failed_dialog));
+    gtk_widget_destroy (failed_dialog);
+
+    g_error_free(error);
+    goto exit;
+  }
+
+#if GLIB_MINOR_VERSION < 14
+  g_hash_table_foreach(sync_items,
+		       get_sync_item_keys,
+		       &item_keys);
+#else
+  item_keys = g_hash_table_get_keys(sync_items);
+#endif
+
+  pship_connections = g_hash_table_new_full(g_int_hash, g_int_equal, g_free, NULL);
+
+  tmp_list = item_keys;
+
+  while (tmp_list) {
+    sync_item_key = (guint *) g_malloc (sizeof (guint));
+    *sync_item_key = GPOINTER_TO_UINT(tmp_list->data);
+
+    g_hash_table_insert(pship_connections, sync_item_key, GUINT_TO_POINTER(0));
+
+    tmp_list = g_list_next(tmp_list);
+  }
+
+  g_list_free(item_keys);
+
+  index = 0;
+  while(index < partnership_list->len)
+    {
+      partnership = g_ptr_array_index(partnership_list, index);
+
+      /* an array of sync item ids - au - array of uint32 */
+      sync_items_active = g_value_get_boxed(g_value_array_get_nth (partnership, 6));
+
+      guint i;
+      guint active_item;
+      guint current_count;
+      for (i = 0; i < sync_items_active->len; i++) {
+	active_item = g_array_index(sync_items_active, guint, i);
+	current_count = GPOINTER_TO_UINT(g_hash_table_lookup(pship_connections, &active_item));
+	current_count++;
+
+	sync_item_key = (guint *) g_malloc (sizeof (guint));
+	*sync_item_key = active_item;
+
+	g_hash_table_insert(pship_connections, sync_item_key, GUINT_TO_POINTER(current_count));
+      }
+
+      index++;
+    }
+
+  show_extra_warning = FALSE;
+  orphaned_items = g_array_new(FALSE, TRUE, sizeof(guint));
+  index = 0;
+  while(index < partnership_list->len)
+    {
+      partnership = g_ptr_array_index(partnership_list, index);
+
+      guint partnership_id = g_value_get_uint(g_value_array_get_nth (partnership, 0));
+      const gchar *partnership_guid = g_value_get_string(g_value_array_get_nth (partnership, 1));
+
+      if ((partnership_id == id) && (strcmp(partnership_guid, guid) == 0)) {
+	sync_items_active = g_value_get_boxed(g_value_array_get_nth (partnership, 6));
+
+	guint i;
+	guint active_item;
+	guint current_count;
+	for (i = 0; i < sync_items_active->len; i++) {
+	  active_item = g_array_index(sync_items_active, guint, i);
+	  current_count = GPOINTER_TO_UINT(g_hash_table_lookup(pship_connections, &active_item));
+
+	  if (current_count == 1) {
+	    show_extra_warning = TRUE;
+	    g_array_append_val(orphaned_items, active_item);
+	  }
+	}
+
+	break;
+      }
+      index++;
+    }
+
+  g_hash_table_destroy(pship_connections);
+
+  if (show_extra_warning) {
+    GString *orphaned_str = NULL;
+    guint i;
+    guint item;
+    gint reply;
+
+    for (i = 0; i < orphaned_items->len; i++) {
+      item = g_array_index(orphaned_items, guint, i);
+     
+      if (!orphaned_str)
+	orphaned_str = g_string_new(g_hash_table_lookup(sync_items, GUINT_TO_POINTER(item)));
+      else
+	g_string_append_printf(orphaned_str, ", %s", (gchar *)g_hash_table_lookup(sync_items, GUINT_TO_POINTER(item)));
+    }
+
+    g_array_free(orphaned_items, TRUE);
+
+    GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(priv->dialog),
+					       GTK_DIALOG_DESTROY_WITH_PARENT,
+					       GTK_MESSAGE_WARNING,
+					       GTK_BUTTONS_YES_NO,
+					       "It appears you are using a Windows Mobile 6 device. Deleting this partnership might result in all items of types %s being deleted from the device because no other partnership is connected with them. Are you really sure you want to delete this partnership?",
+					       orphaned_str->str);
+
+    gtk_window_set_title(GTK_WINDOW(dialog), "Possible deletion of 'orphaned' items");
+    reply = gtk_dialog_run(GTK_DIALOG(dialog));
+    gtk_widget_destroy (dialog);
+
+    g_string_free(orphaned_str, TRUE);
+
+    if (reply != GTK_RESPONSE_YES)
+      result = FALSE;
+    else
+      result = TRUE;
+
+  } else
+    result = TRUE;
+
+exit:
+
+  if (partnership_list) {
+    index = 0;
+    while(index < partnership_list->len) {
+      partnership = g_ptr_array_index(partnership_list, index);
+      g_value_array_free(partnership);
+
+      index++;
+    }
+    g_ptr_array_free(partnership_list, TRUE);
+  }
+
+  if (sync_items) g_hash_table_destroy(sync_items);
+
+  if (sync_engine_proxy) g_object_unref(sync_engine_proxy);
+  if (dbus_connection) dbus_g_connection_unref(dbus_connection);
+
+  return result;
+}
+
+
 static void
 partners_remove_button_clicked_synceng_cb (GtkWidget *widget, gpointer data)
 {
@@ -544,9 +793,10 @@
   }
 
   guint index, id;
+  guint os_major, os_minor;
   gchar *guid = NULL;
   gchar *name;
-  GtkTreeIter iter;
+  GtkTreeIter iter, parent_iter;
   GtkTreeModel *model;
   GtkWidget *partners_list_view = glade_xml_get_widget (priv->xml, "partners_list");	
   GtkTreeSelection *selection = gtk_tree_view_get_selection (GTK_TREE_VIEW (partners_list_view));
@@ -572,6 +822,20 @@
       return;
     }
 
+  /* if the user selected one of the subitems */
+
+  if (gtk_tree_model_iter_parent(model, &parent_iter, &iter)) {
+    g_free(guid);
+    g_free(name);
+    gtk_tree_model_get (model,
+			&parent_iter,
+			SYNCENG_INDEX_COLUMN, &index,
+			SYNCENG_ID_COLUMN, &id,
+			SYNCENG_GUID_COLUMN, &guid,
+			SYNCENG_NAME_COLUMN, &name,
+			-1);
+  }
+
   GtkWidget *device_info_dialog = priv->dialog;
   GtkWidget *confirm_dialog = gtk_message_dialog_new(GTK_WINDOW(device_info_dialog),
 						     GTK_DIALOG_DESTROY_WITH_PARENT,
@@ -628,6 +892,21 @@
     goto exit;
   }
 
+  /*
+    Check whether the removal of this particular partnership would result
+    in orphaned itemtypes, that would be deleted by wm6
+  */
+
+  g_object_get(priv->device,
+	       "os-major", &os_major,
+	       "os-minor", &os_minor,
+	       NULL);
+
+  if ((os_major > 4) && (os_minor > 1)) {
+    if (!check_delete_orphans(self, id, guid))
+      goto exit;
+  }
+
   result = org_synce_syncengine_delete_partnership(sync_engine_proxy, id, guid, &error);
   if (!result) {
     g_critical("%s: Error deleting partnership via sync-engine: %s", G_STRFUNC, error->message);
@@ -673,7 +952,7 @@
   GtkTreeModel *model;
   gint index, id;
   gchar *name;
-  GtkWidget *partners_create_button, *partners_remove_button;
+  GtkWidget *partners_remove_button;
 
   partners_remove_button = glade_xml_get_widget (priv->xml, "partners_remove_button");	
 
@@ -701,15 +980,6 @@
 }
 
 
-#if GLIB_MINOR_VERSION < 14
-get_sync_item_keys(gpointer key,
-		   gpointer value,
-		   gpointer user_data)
-{
-  *(GList **)user_data = g_list_append(*(GList **)user_data, key);
-}
-#endif
-
 static void
 partners_setup_view_store_synceng(WmDeviceInfo *self)
 {
@@ -1765,9 +2035,6 @@
 static void
 wm_device_info_finalize (GObject *obj)
 {
-  WmDeviceInfo *self = WM_DEVICE_INFO(obj);
-  WmDeviceInfoPrivate *priv = WM_DEVICE_INFO_GET_PRIVATE (self);
-
   if (G_OBJECT_CLASS (wm_device_info_parent_class)->finalize)
     G_OBJECT_CLASS (wm_device_info_parent_class)->finalize (obj);
 }
