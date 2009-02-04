--- src/jingle-factory.c.orig	2009-02-04 15:04:28.000000000 -0500
+++ src/jingle-factory.c	2009-02-04 15:10:48.000000000 -0500
@@ -91,10 +91,10 @@ gabble_jingle_factory_init (GabbleJingle
       g_free, g_object_unref);
 
   obj->transports = g_hash_table_new_full (g_str_hash, g_str_equal,
-      NULL, NULL);
+      NULL, (GDestroyNotify) g_free);
 
   obj->content_types = g_hash_table_new_full (g_str_hash, g_str_equal,
-      NULL, NULL);
+      NULL, (GDestroyNotify) g_free);
 
   priv->jingle_cb = NULL;
 
@@ -606,16 +606,22 @@ void
 gabble_jingle_factory_register_transport (GabbleJingleFactory *factory,
     gchar *namespace, GType transport_type)
 {
-  g_hash_table_insert (factory->transports, namespace,
-      GINT_TO_POINTER (transport_type));
+  GabbleJingleFactoryHashType *htype;
+
+  htype = g_new (GabbleJingleFactoryHashType, 1);
+  htype->type = transport_type;
+  g_hash_table_insert (factory->transports, namespace, htype);
 }
 
 void
 gabble_jingle_factory_register_content_type (GabbleJingleFactory *factory,
     gchar *namespace, GType content_type)
 {
-  g_hash_table_insert (factory->content_types, namespace,
-      GINT_TO_POINTER (content_type));
+  GabbleJingleFactoryHashType *htype;
+
+  htype = g_new (GabbleJingleFactoryHashType, 1);
+  htype->type = content_type;
+  g_hash_table_insert (factory->content_types, namespace, htype);
 }
 
 static void
