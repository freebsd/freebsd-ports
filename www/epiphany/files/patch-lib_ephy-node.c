Index: lib/ephy-node.c
===================================================================
RCS file: /cvs/gnome/epiphany/lib/ephy-node.c,v
retrieving revision 1.19
diff -u -p -r1.19 ephy-node.c
--- lib/ephy-node.c	9 Jun 2003 13:06:19 -0000	1.19
+++ lib/ephy-node.c	28 Jun 2003 22:46:29 -0000
@@ -64,6 +64,12 @@ struct EphyNode
 	EphyNodeDb *db;
 };
 
+typedef struct
+{
+	EphyNodeSignalType type;
+	va_list valist;
+} ENESCData;
+
 /* evillish hacks to temporarily readlock->writelock and v.v. */
 static inline void
 write_lock_to_read_lock (EphyNode *node)
@@ -113,14 +119,16 @@ int_hash (gconstpointer a)
 }
 
 static void
-callback (long id, EphyNodeSignalData *data, gpointer *user_data)
+callback (long id, EphyNodeSignalData *data, gpointer *dummy)
 {
-        va_list valist;
-	EphyNodeSignalType type = GPOINTER_TO_INT (user_data[1]);
+	ENESCData *user_data;
+	va_list valist;
 
-	if (data->type != type) return;
+	user_data = (ENESCData *) dummy;
 
-        va_copy(valist, user_data[0]);
+	valist = user_data->valist;
+
+	if (data->type != user_data->type) return;
 
 	switch (data->type)
 	{
@@ -155,18 +163,17 @@ callback (long id, EphyNodeSignalData *d
 static void
 ephy_node_emit_signal (EphyNode *node, EphyNodeSignalType type, ...)
 {
-	va_list valist;
-	gpointer data[2];
+	ENESCData data;
+
+	va_start (data.valist, type);
 
-	va_start (valist, type);
+	data.type = type;
 
-	data[0] = (gpointer)valist;
-	data[1] = GINT_TO_POINTER (type);
 	g_hash_table_foreach (node->signals,
 			      (GHFunc) callback,
-			      data);
+			      &data);
 
-	va_end (valist);
+	va_end (data.valist);
 }
 
 static void
