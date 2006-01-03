--- src/slashexec.c.orig	Tue Aug  2 08:52:03 2005
+++ src/slashexec.c	Tue Jan  3 15:52:55 2006
@@ -55,6 +55,9 @@
 	gchar buffer[MAX_COMMAND_LEN], **argv;
 	GError *error;
 	gint argc;
+	gchar *standard_output = NULL, *standard_error = NULL;
+	GSpawnFlags Gflags;
+	Gflags = G_SPAWN_SEARCH_PATH;
 	error = NULL;
 	/* TODO: need to properly escape cmd at some stage*/
 	gaim_debug_info("slashexec", "Executing: %s\n", cmd);
@@ -70,9 +73,6 @@
 		g_strfreev(argv);
 		return NULL;
 	}
-	gchar *standard_output = NULL, *standard_error = NULL;
-	GSpawnFlags Gflags;
-	Gflags = G_SPAWN_SEARCH_PATH;
 	if (!g_spawn_sync (NULL, argv, NULL, Gflags,
 		NULL, NULL, &standard_output, &standard_error, NULL, &error)) {
 		if (buffer)
