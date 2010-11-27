--- src/pk-lsof.c.orig	2010-10-21 12:50:10.000000000 -0400
+++ src/pk-lsof.c	2010-11-27 00:13:21.000000000 -0500
@@ -154,7 +154,7 @@ pk_lsof_refresh (PkLsof *lsof)
 	g_return_val_if_fail (PK_IS_LSOF (lsof), FALSE);
 
 	/* try to find lsof */
-	lsof_name = "/usr/sbin/lsof";
+	lsof_name = "%%LOCALBASE%%/sbin/lsof";
 	ret = g_file_test (lsof_name, G_FILE_TEST_EXISTS);
 	if (!ret) {
 		lsof_name = "/usr/bin/lsof";
--- src/pk-lsof.c.orig	2010-01-09 15:57:54.000000000 -0500
+++ src/pk-lsof.c	2010-01-09 15:58:15.000000000 -0500
@@ -153,7 +153,7 @@ pk_lsof_refresh (PkLsof *lsof)
 	g_return_val_if_fail (PK_IS_LSOF (lsof), FALSE);
 
 	/* run lsof to get all data */
-	ret = g_spawn_command_line_sync ("/usr/sbin/lsof -Fpfn", &stdout, &stderr, NULL, &error);
+	ret = g_spawn_command_line_sync ("%%LOCALBASE%%/sbin/lsof -Fpfn", &stdout, &stderr, NULL, &error);
 	if (!ret) {
 		egg_warning ("failed to get pids: %s", error->message);
 		g_error_free (error);
