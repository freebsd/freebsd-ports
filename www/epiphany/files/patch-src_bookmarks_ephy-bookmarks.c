--- src/bookmarks/ephy-bookmarks.c	2008/01/14 19:29:31	7863
+++ src/bookmarks/ephy-bookmarks.c	2008/03/13 14:09:36	8102
@@ -136,39 +136,10 @@
 static void ephy_bookmarks_finalize	(GObject *object);
 static char *impl_resolve_address	(EphyBookmarks*, const char*, const char*);
 
-static GObjectClass *parent_class = NULL;
-
-GType
-ephy_bookmarks_get_type (void)
-{
-	static GType type = 0;
-
-	if (G_UNLIKELY (type == 0))
-	{
-		const GTypeInfo our_info =
-		{
-			sizeof (EphyBookmarksClass),
-			NULL, /* base_init */
-			NULL, /* base_finalize */
-			(GClassInitFunc) ephy_bookmarks_class_init,
-			NULL,
-			NULL, /* class_data */
-			sizeof (EphyBookmarks),
-			0, /* n_preallocs */
-			(GInstanceInitFunc) ephy_bookmarks_init
-		};
-		volatile GType flags_type; /* work around gcc's optimiser */
-      
-		/* make sure the flags type is known */
-	      	flags_type = EPHY_TYPE_BOOKMARK_PROPERTY;
-
-		type = g_type_register_static (G_TYPE_OBJECT,
-					       "EphyBookmarks",
-					       &our_info, 0);
-	}
-
-	return type;
-}
+G_DEFINE_TYPE_WITH_CODE (EphyBookmarks, ephy_bookmarks, G_TYPE_OBJECT,
+			 volatile GType flags_type; /* work around gcc's optimiser */
+			 /* make sure the flags type is known */
+		      	 flags_type = EPHY_TYPE_BOOKMARK_PROPERTY;)
 
 static void
 ephy_bookmarks_init_defaults (EphyBookmarks *eb)
@@ -194,8 +165,6 @@
 {
 	GObjectClass *object_class = G_OBJECT_CLASS (klass);
 
-	parent_class = g_type_class_peek_parent (klass);
-
 	object_class->finalize = ephy_bookmarks_finalize;
 
 	klass->resolve_address = impl_resolve_address;
@@ -799,7 +768,10 @@
 	char *key_dup, *value_dup;
 	char *raw_txt;
 	size_t raw_txt_len;
-	
+
+	if (!input_text)
+		return NULL;
+
 	raw_txt_len = avahi_string_list_serialize (input_text, NULL, 0);
 	raw_txt = g_malloc (raw_txt_len);
 	raw_txt_len = avahi_string_list_serialize (input_text, raw_txt, raw_txt_len);
@@ -868,41 +840,14 @@
 				name);
 }
 
-static EphyNode *
-get_node_for_id (EphyBookmarks *bookmarks,
-		 char *node_id)
-{
-	EphyBookmarksPrivate *priv = bookmarks->priv;
-	EphyNode *kid, *node = NULL;
-	GPtrArray *children;
-	const char *id;
-	guint i;
-
-	children = ephy_node_get_children (priv->local);
-	for (i = 0; i < children->len; i++)
-	{
-		kid = g_ptr_array_index (children, i);
-
-		id = ephy_node_get_property_string (kid,
-						    EPHY_NODE_BMK_PROP_SERVICE_ID);
-
-		if (g_str_equal (id, node_id))
-		{
-			node = kid;
-			break;
-		}
-	}
-
-	g_free (node_id);
-
-	return node;
-}
-
 typedef struct
 {
 	EphyBookmarks *bookmarks;
+	GaServiceResolver *resolver;
 	EphyNode *node;
-	guint new_node : 1;
+	char *name;
+	char *type;
+	char *domain;
 } ResolveData;
 
 static void
@@ -921,20 +866,20 @@
 {
 	EphyBookmarks *bookmarks = data->bookmarks;
 	EphyBookmarksPrivate *priv = bookmarks->priv;
-	EphyNode *node = data->node;
 	GValue value = { 0, };
 	const char *path = NULL;
 	char host[128];
 	GHashTable *text_table;
 	char *url;
 	gboolean was_immutable;
+	gboolean is_new_node = FALSE;
 	guint i;
 
+	LOG ("resolver_found_cb resolver %p\n", resolver);
+
 	was_immutable = ephy_node_db_is_immutable (priv->db);
 	ephy_node_db_set_immutable (priv->db, FALSE);
 
-	g_hash_table_steal (priv->resolve_handles, node);
-	
 	/* Find the protocol */
 	for (i = 0; i < G_N_ELEMENTS (zeroconf_protos); ++i)
 	{
@@ -945,6 +890,12 @@
 	}
 	if (i == G_N_ELEMENTS (zeroconf_protos)) return;
 	
+	if (address == NULL)
+	{
+		g_warning ("Zeroconf failed to resolve host %s", name);
+		return;
+	}
+
 	text_table = decode_txt_record (txt);
 
 	if (text_table != NULL)
@@ -956,32 +907,60 @@
 		path = "/";
 	}
 	
-	if (address == NULL)
-	{
-		g_warning ("Zeroconf failed to resolve host %s", name);
-		return;
-	}
 	avahi_address_snprint (host, sizeof (host), address);
 
 	LOG ("0conf RESOLVED type=%s domain=%s name=%s => proto=%s host=%s port=%d path=%s\n",
 	     type, domain, name,
 	     zeroconf_protos[i], host, port, path);
 
+	was_immutable = ephy_node_db_is_immutable (priv->db);
+	ephy_node_db_set_immutable (priv->db, FALSE);
+
+	if (data->node == NULL)
+	{
+		is_new_node = TRUE;
+
+		data->node = ephy_node_new (priv->db);
+		g_assert (data->node != NULL);
+
+		/* don't allow dragging this node */
+		ephy_node_set_is_drag_source (data->node, FALSE);
+
+		g_value_init (&value, G_TYPE_STRING);
+		g_value_take_string (&value,
+				     get_id_for_response (data->type, 
+							  data->domain,
+							  data->name));
+		ephy_node_set_property (data->node, EPHY_NODE_BMK_PROP_SERVICE_ID, &value);
+		g_value_unset (&value);
+
+		/* FIXME: limit length! */
+		ephy_node_set_property_string (data->node,
+					       EPHY_NODE_BMK_PROP_TITLE,
+					       name);
+
+		ephy_node_set_property_boolean (data->node,
+						EPHY_NODE_BMK_PROP_IMMUTABLE,
+						TRUE);
+	}
+
 	/* FIXME: limit length! */
 	url = g_strdup_printf ("%s://%s:%d%s", zeroconf_protos[i], host, port, path);
 
 	g_value_init (&value, G_TYPE_STRING);
 	g_value_take_string (&value, url);
-	ephy_node_set_property (node, EPHY_NODE_BMK_PROP_LOCATION, &value);
+	ephy_node_set_property (data->node, EPHY_NODE_BMK_PROP_LOCATION, &value);
 	g_value_unset (&value);
 
-	if (data->new_node)
+	if (is_new_node)
 	{
-		ephy_node_add_child (priv->bookmarks, node);
-		ephy_node_add_child (priv->local, node);
+		ephy_node_add_child (priv->bookmarks, data->node);
+		ephy_node_add_child (priv->local, data->node);
 	}
 	
 	ephy_node_db_set_immutable (priv->db, was_immutable);
+
+	g_hash_table_unref (text_table);
 }
 
 static void
@@ -989,53 +968,33 @@
 		     GError *error,
 		     ResolveData *data)
 {
-	EphyBookmarks *bookmarks = data->bookmarks;
-	EphyBookmarksPrivate *priv = bookmarks->priv;
-	EphyNode *node = data->node;
-	gboolean was_immutable;
+	LOG ("resolver_failure_cb resolver %p: %s\n", resolver, error?error->message:"(null)");
 
-	was_immutable = ephy_node_db_is_immutable (priv->db);
-	ephy_node_db_set_immutable (priv->db, FALSE);
-
-	g_hash_table_steal (priv->resolve_handles, node);
-
-	/* Error, don't add the service */
-	ephy_node_unref (node);
-	ephy_node_db_set_immutable (priv->db, was_immutable);
-
-	return;
-}
+	/* Remove the node, if present */
+	if (data->node != NULL)
+	{	
+		EphyBookmarks *bookmarks = data->bookmarks;
+		EphyBookmarksPrivate *priv = bookmarks->priv;
+		gboolean was_immutable;
 
-static void
-free_resolve_cb_data (gpointer data)
-{
-	g_slice_free (ResolveData, data);
+		was_immutable = ephy_node_db_is_immutable (priv->db);
+		ephy_node_db_set_immutable (priv->db, FALSE);	
+		ephy_node_unref (data->node);
+		data->node = NULL;
+		ephy_node_db_set_immutable (priv->db, was_immutable);
+	}
 }
 
 static void
-browser_removed_service_cb (GaServiceBrowser *browser,
-			    int interface,
-			    GaProtocol protocol,
-			    const char *name,
-			    const char *type,
-			    const char *domain,
-			    glong flags,
-			    EphyBookmarks *bookmarks)
+resolve_data_free (ResolveData* data)
 {
-	EphyBookmarksPrivate *priv = bookmarks->priv;
-	EphyNode *node;
-	char *node_id;
-	
-	node_id = get_id_for_response (type, domain, name);
-	node = get_node_for_id (bookmarks, node_id);
+	if (data->resolver)
+		g_object_unref (data->resolver);
 
-	if (node != NULL)
-	{
-		g_hash_table_remove (priv->resolve_handles, node);
-		ephy_node_unref (node);
-	}
-	
-	return;
+	g_free (data->type);
+	g_free (data->name);
+	g_free (data->domain);
+	g_slice_free (ResolveData, data);
 }
 
 static void
@@ -1049,81 +1008,88 @@
 			EphyBookmarks *bookmarks)
 {
 	EphyBookmarksPrivate *priv = bookmarks->priv;
-	EphyNode *node;
-	GValue value = { 0, };
-	gboolean new_node = FALSE;
-	GaServiceResolver *resolver = NULL;
 	ResolveData *data;
 	char *node_id;
+	GError *error = NULL;
 	
 	node_id = get_id_for_response (type, domain, name);
-	node = get_node_for_id (bookmarks, node_id);
 	
 	LOG ("0conf ADD: type=%s domain=%s name=%s\n",
 	     type, domain, name);
 	
-		if (node != NULL &&
-	    g_hash_table_lookup (priv->resolve_handles, node) != NULL) return;
-
-	if (node == NULL)
+	if (g_hash_table_lookup (priv->resolve_handles, node_id) != NULL)
 	{
-		gboolean was_immutable;
-
-		was_immutable = ephy_node_db_is_immutable (priv->db);
-		ephy_node_db_set_immutable (priv->db, FALSE);
-
-		node = ephy_node_new (priv->db);
-		g_assert (node != NULL);
-
-		new_node = TRUE;
-
-		/* don't allow dragging this node */
-		ephy_node_set_is_drag_source (node, FALSE);
-
-		g_value_init (&value, G_TYPE_STRING);
-		g_value_take_string (&value, get_id_for_response (type, domain, name));
-		ephy_node_set_property (node, EPHY_NODE_BMK_PROP_SERVICE_ID, &value);
-		g_value_unset (&value);
-
-		/* FIXME: limit length! */
-		ephy_node_set_property_string (node,
-					       EPHY_NODE_BMK_PROP_TITLE,
-					       name);
-
-		ephy_node_set_property_boolean (node,
-						EPHY_NODE_BMK_PROP_IMMUTABLE,
-						TRUE);
-
-		ephy_node_db_set_immutable (priv->db, was_immutable);
+		g_free (node_id);
+		return;
 	}
 
 	data = g_slice_new0 (ResolveData);
 	data->bookmarks = bookmarks;
-	data->node = node;
-	data->new_node = new_node;
-	
-	resolver = ga_service_resolver_new (AVAHI_IF_UNSPEC,
-					    AVAHI_PROTO_UNSPEC,
-					    name, type, domain,
-					    AVAHI_PROTO_UNSPEC,
-					    GA_LOOKUP_USE_MULTICAST);
-	g_signal_connect_data (resolver, "found",
-			       G_CALLBACK (resolver_found_cb), data,
-			       (GClosureNotify) free_resolve_cb_data, 0);
-	g_signal_connect_data (resolver, "failure",
-			       G_CALLBACK (resolver_failure_cb), data,
-			       (GClosureNotify) free_resolve_cb_data, 0);
-	if (!ga_service_resolver_attach (resolver,
+	data->node = NULL;
+	data->type = g_strdup (type);
+	data->name = g_strdup (name);
+	data->domain = g_strdup (domain);
+	
+	data->resolver = ga_service_resolver_new (AVAHI_IF_UNSPEC,
+						  AVAHI_PROTO_UNSPEC,
+						  name, type, domain,
+						  AVAHI_PROTO_UNSPEC,
+						  GA_LOOKUP_USE_MULTICAST);
+	g_signal_connect (data->resolver, "found",
+			  G_CALLBACK (resolver_found_cb), data);
+	g_signal_connect (data->resolver, "failure",
+			  G_CALLBACK (resolver_failure_cb), data);
+	if (!ga_service_resolver_attach (data->resolver,
 					 priv->ga_client,
-					 NULL))
+					 &error))
 	{
-		g_warning ("Unable to resolve Zeroconf service %s", name);
-		ephy_node_unref (node);
-		free_resolve_cb_data (data);
+		g_warning ("Unable to resolve Zeroconf service %s: %s", name, error ? error->message : "(null)");
+		g_clear_error (&error);
+		resolve_data_free (data);
+		g_free (node_id);
 		return;
 	}
+
 	g_hash_table_insert (priv->resolve_handles,
-			     node, resolver);
+			     node_id /* transfer ownership */, data);
+}
+
+static void
+browser_removed_service_cb (GaServiceBrowser *browser,
+			    int interface,
+			    GaProtocol protocol,
+			    const char *name,
+			    const char *type,
+			    const char *domain,
+			    glong flags,
+			    EphyBookmarks *bookmarks)
+{
+	EphyBookmarksPrivate *priv = bookmarks->priv;
+	char *node_id;
+	ResolveData *data;
+
+	node_id = get_id_for_response (type, domain, name);
+	data = g_hash_table_lookup (priv->resolve_handles, node_id);
+	/* shouldn't really happen, but let's play safe */
+	if (!data)
+	{
+		g_free (node_id);
+		return;
+	}
+
+	if (data->node != NULL)
+	{	
+		gboolean was_immutable;
+
+		was_immutable = ephy_node_db_is_immutable (priv->db);
+		ephy_node_db_set_immutable (priv->db, FALSE);	
+		ephy_node_unref (data->node);
+		data->node = NULL;
+		ephy_node_db_set_immutable (priv->db, was_immutable);
+	}
+
+	g_hash_table_remove (priv->resolve_handles, node_id);
+	g_free (node_id);
 }
 
 static void
@@ -1150,9 +1116,10 @@
 						NULL))
 		{
 			g_warning ("Unable to start Zeroconf subsystem");
+			g_object_unref (browser);
 			return;
 		}
-		
+
 		priv->browse_handles[i] = browser;
 	}
 }
@@ -1166,6 +1133,7 @@
 	{
 		if (avahi_client_errno (ga_client->avahi_client) == AVAHI_ERR_DISCONNECTED)
 		{
+			/* FIXMEchpe: is this correct */
 			/* Destroy and reconnect */
 			avahi_client_free (ga_client->avahi_client);
 			ga_client->avahi_client = NULL;
@@ -1197,7 +1165,9 @@
 		return;
 	}
 	priv->ga_client = ga_client;
-	priv->resolve_handles =	g_hash_table_new (g_direct_hash, g_direct_equal);
+	priv->resolve_handles =	g_hash_table_new_full (g_str_hash, g_str_equal,
+						       g_free,
+						       (GDestroyNotify) resolve_data_free);
 }
 
 static void
@@ -1210,6 +1180,7 @@
 	{
 		if (priv->browse_handles[i] != NULL)
 		{
+			g_object_unref (priv->browse_handles[i]);
 			priv->browse_handles[i] = NULL;
 		}
 	}
@@ -1222,7 +1193,8 @@
 
 	if (priv->local != NULL)
 	{
-		ephy_node_remove_child (priv->keywords, priv->local);
+		ephy_node_unref (priv->local);
+		priv->local = NULL;
 	}
 	
 	if (priv->ga_client != NULL)
@@ -1431,7 +1403,7 @@
 
 	LOG ("Bookmarks finalized");
 
-	G_OBJECT_CLASS (parent_class)->finalize (object);
+	G_OBJECT_CLASS (ephy_bookmarks_parent_class)->finalize (object);
 }
 
 EphyBookmarks *
