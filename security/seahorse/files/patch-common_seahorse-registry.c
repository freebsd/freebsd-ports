--- common/seahorse-registry.c.orig	2009-02-14 19:20:38.000000000 +0100
+++ common/seahorse-registry.c	2009-02-24 21:15:26.000000000 +0100
@@ -51,6 +51,25 @@
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
@@ -63,13 +82,14 @@
                              gpointer value, GDestroyNotify destroy_func)
 {
 	GHashTable *set;
+	SeahorseRegistryType *rtype;
 	
 	g_return_if_fail (table);
 	g_return_if_fail (category);
 	
 	set = g_hash_table_lookup (table, GUINT_TO_POINTER (category));
 	if (!set) {
-		set = g_hash_table_new_full (g_direct_hash, g_direct_equal, destroy_func, NULL);
+		set = g_hash_table_new_full (registry_hash, registry_equal, destroy_func, NULL);
 		g_hash_table_replace (table, GUINT_TO_POINTER (category), set);
 	}
 	
