--- src/jingle-session.c.orig	2009-02-04 15:15:32.000000000 -0500
+++ src/jingle-session.c	2009-02-04 15:33:12.000000000 -0500
@@ -602,6 +602,7 @@ _each_content_add (GabbleJingleSession *
   const gchar *name = lm_message_node_get_attribute (content_node, "name");
   LmMessageNode *desc_node = lm_message_node_get_child_any_ns (content_node,
       "description");
+  GabbleJingleFactoryHashType *htype;
   GType content_type = 0;
   const gchar *content_ns = NULL;
 
@@ -609,9 +610,10 @@ _each_content_add (GabbleJingleSession *
     {
       content_ns = lm_message_node_get_namespace (desc_node);
       DEBUG ("namespace: %s", content_ns);
-      content_type =
-          GPOINTER_TO_INT (g_hash_table_lookup (priv->conn->jingle_factory->content_types,
-          content_ns));
+      htype = g_hash_table_lookup (priv->conn->jingle_factory->content_types,
+          content_ns);
+      if (htype)
+        content_type = htype->type;
     }
 
   if (content_type == 0)
@@ -1597,7 +1599,8 @@ gabble_jingle_session_add_content (Gabbl
 {
   GabbleJingleSessionPrivate *priv = GABBLE_JINGLE_SESSION_GET_PRIVATE (sess);
   GabbleJingleContent *c;
-  GType content_type;
+  GabbleJingleFactoryHashType *htype;
+  GType content_type = 0;
   gchar *name = NULL;
   gint id = g_hash_table_size (priv->contents) + 1;
 
@@ -1608,9 +1611,10 @@ gabble_jingle_session_add_content (Gabbl
     }
   while (g_hash_table_lookup (priv->contents, name) != NULL);
 
-  content_type =
-      GPOINTER_TO_INT (g_hash_table_lookup (priv->conn->jingle_factory->content_types,
-      content_ns));
+  htype = g_hash_table_lookup (priv->conn->jingle_factory->content_types,
+      content_ns);
+  if (htype)
+    content_type = htype->type;
 
   g_assert (content_type != 0);
 
