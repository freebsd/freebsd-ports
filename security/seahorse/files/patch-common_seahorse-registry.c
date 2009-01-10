--- common/seahorse-registry.c.orig	2008-11-23 18:26:38.000000000 -0500
+++ common/seahorse-registry.c	2008-11-23 19:20:08.000000000 -0500
@@ -49,6 +49,25 @@ cleanup_registry (void *unused)
 	registry_singleton = NULL;
 }
 
+static guint registry_hash (gconstpointer key)
+{
+	SeahorseRegistryType *rtype;
+
+	rtype = (SeahorseRegistryType *) key;
+
+	return (guint) rtype->type;
+}
+
+static gboolean registry_equal (gconstpointer a, gconstpointer b)
+{
+	SeahorseRegistryType *rta, *rtb;
+
+	rta = (SeahorseRegistryType *) a;
+	rtb = (SeahorseRegistryType *) b;
+
+	return (rta->type == rtb->type);
+}
+
 static void
 keys_to_list (gpointer key, gpointer value, gpointer user_data)
 {
@@ -61,6 +80,7 @@ register_type_for_category (SeahorseRegi
 {
 	SeahorseRegistryPrivate *pv = SEAHORSE_REGISTRY_GET_PRIVATE (registry);
 	GHashTable *set;
+	SeahorseRegistryType *rtype;
 	
 	g_return_if_fail (SEAHORSE_IS_REGISTRY (registry));
 	g_return_if_fail (category);
@@ -68,11 +88,14 @@ register_type_for_category (SeahorseRegi
 	
 	set = g_hash_table_lookup (pv->categories, category);
 	if (!set) {
-		set = g_hash_table_new_full (g_direct_hash, g_direct_equal, NULL, NULL);
+		set = g_hash_table_new_full (registry_hash, registry_equal, (GDestroyNotify) g_free, NULL);
 		g_hash_table_replace (pv->categories, g_strdup (category), set);
 	}
+
+	rtype = g_new (SeahorseRegistryType, 1);
+	rtype->type = type;
 	
-	g_hash_table_replace (set, GUINT_TO_POINTER (type), NO_VALUE);
+	g_hash_table_replace (set, rtype, NO_VALUE);
 }
 
 static GList*
@@ -115,6 +138,7 @@ lookup_types (SeahorseRegistry *registry
 		
 		/* Go through each item in list and make sure it exists in this cat */
 		for (l = types; l; l = l ? g_list_next (l) : types) {
+			SeahorseRegistryType *rtype;
 			type = l;
 			if (!g_hash_table_lookup (set, type->data)) {
 				l = g_list_previous (l);
@@ -224,8 +248,12 @@ seahorse_registry_find_type (SeahorseReg
 	va_end (cats);
 
 	type = 0;
-	if (types)
-		type = GPOINTER_TO_UINT (types->data);
+	if (types) {
+		SeahorseRegistryType *rtype;
+
+		rtype = (SeahorseRegistryType *) types->data;
+		type = rtype->type;
+	}
 	g_list_free (types);
 	return type;
 }
