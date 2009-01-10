--- src/seahorse-viewer.c.orig	2008-11-23 18:27:49.000000000 -0500
+++ src/seahorse-viewer.c	2008-11-23 18:28:27.000000000 -0500
@@ -556,10 +556,13 @@ seahorse_viewer_constructor (GType type,
 		/* Setup the commands */
 		types = seahorse_registry_find_types (seahorse_registry_get (), "commands", NULL, NULL);
 		for (l = types; l; l = g_list_next (l)) {
-			GType typ = GPOINTER_TO_INT (l->data);
+			SeahorseRegistryType *rtype = (SeahorseRegistryType *) l->data;
+			GType typ;
 			SeahorseCommands *commands;
 			GtkActionGroup *actions;
 			const gchar *uidef;
+
+			typ = rtype->type;
 			
 			/* Add each commands to our hash table */
 			commands = g_object_new (typ, "view", self, NULL);
