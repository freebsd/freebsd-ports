--- src/jingle-content.c.orig	2009-02-04 15:11:10.000000000 -0500
+++ src/jingle-content.c	2009-02-04 15:32:51.000000000 -0500
@@ -217,9 +217,12 @@ gabble_jingle_content_set_property (GObj
 
       if (priv->transport_ns != NULL)
         {
-          GType transport_type = GPOINTER_TO_INT (
-              g_hash_table_lookup (self->conn->jingle_factory->transports,
-                  priv->transport_ns));
+          GabbleJingleFactoryHashType *htype;
+	  GType transport_type = 0;
+          htype = g_hash_table_lookup (self->conn->jingle_factory->transports,
+                  priv->transport_ns);
+	  if (htype)
+	    transport_type = htype->type;
 
           g_assert (transport_type != 0);
 
@@ -448,6 +451,7 @@ gabble_jingle_content_parse_add (GabbleJ
   GabbleJingleContentPrivate *priv = GABBLE_JINGLE_CONTENT_GET_PRIVATE (c);
   const gchar *name, *creator, *senders, *disposition;
   LmMessageNode *trans_node, *desc_node;
+  GabbleJingleFactoryHashType *htype;
   GType transport_type = 0;
   GabbleJingleTransportIface *trans = NULL;
   JingleDialect dialect;
@@ -480,8 +484,9 @@ gabble_jingle_content_parse_add (GabbleJ
 
           dialect = JINGLE_DIALECT_GTALK3;
           g_object_set (c->session, "dialect", JINGLE_DIALECT_GTALK3, NULL);
-          transport_type = GPOINTER_TO_INT (
-              g_hash_table_lookup (c->conn->jingle_factory->transports, ""));
+          htype = g_hash_table_lookup (c->conn->jingle_factory->transports, "");
+	  if (htype)
+	    transport_type = htype->type;
           priv->transport_ns = g_strdup ("");
         }
     }
@@ -499,8 +504,9 @@ gabble_jingle_content_parse_add (GabbleJ
     {
       const gchar *ns = lm_message_node_get_namespace (trans_node);
 
-      transport_type = GPOINTER_TO_INT (
-          g_hash_table_lookup (c->conn->jingle_factory->transports, ns));
+      htype = g_hash_table_lookup (c->conn->jingle_factory->transports, ns);
+      if (htype)
+        transport_type = htype->type;
 
       if (transport_type == 0)
         {
