--- src/pk-backend-spawn.c.orig	2010-04-04 21:23:33.000000000 -0400
+++ src/pk-backend-spawn.c	2010-04-04 21:22:08.000000000 -0400
@@ -674,7 +674,7 @@ pk_backend_spawn_get_envp (PkBackendSpaw
 	gchar *line;
 	gchar *uri;
 	gchar *eulas;
-	gchar *transaction_id;
+	gchar *transaction_id = NULL;
 	guint i;
 	GPtrArray *array;
 	gboolean ret;
