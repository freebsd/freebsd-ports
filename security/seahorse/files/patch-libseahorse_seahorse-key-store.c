--- libseahorse/seahorse-key-store.c.orig	Wed Dec 22 15:18:27 2004
+++ libseahorse/seahorse-key-store.c	Wed Dec 22 15:19:48 2004
@@ -184,6 +184,8 @@
 {
     GObject* obj = G_OBJECT_CLASS (parent_class)->constructor (type, n_props, props);
     SeahorseKeyStore* skstore = SEAHORSE_KEY_STORE (obj);
+    guint cols;
+    GType* types;
 
     /* init private vars */
     skstore->priv = g_new0 (SeahorseKeyStorePriv, 1);
@@ -191,8 +193,8 @@
                                        NULL, (GDestroyNotify)seahorse_key_row_free);
  
     /* Setup the store */
-    guint cols = SEAHORSE_KEY_STORE_GET_CLASS (skstore)->n_columns;
-    GType* types = (GType*)SEAHORSE_KEY_STORE_GET_CLASS (skstore)->col_types;
+    cols = SEAHORSE_KEY_STORE_GET_CLASS (skstore)->n_columns;
+    types = (GType*)SEAHORSE_KEY_STORE_GET_CLASS (skstore)->col_types;
     gtk_tree_store_set_column_types (GTK_TREE_STORE (obj), cols, types);
     
     /* Setup the sort and filter */
