--- lib/utilunix.c.orig	2015-04-12 03:04:27 UTC
+++ lib/utilunix.c
@@ -528,7 +528,7 @@ mc_popen (const char *command, GError **
         goto ret_err;
     }
 
-    if (!g_spawn_async_with_pipes (NULL, argv, NULL, G_SPAWN_DO_NOT_REAP_CHILD, NULL, NULL,
+    if (!g_spawn_async_with_pipes (NULL, argv, NULL, G_SPAWN_DO_NOT_REAP_CHILD | G_SPAWN_SEARCH_PATH, NULL, NULL,
                                    &p->child_pid, NULL, &p->out.fd, &p->err.fd, error))
     {
         mc_replace_error (error, MC_PIPE_ERROR_CREATE_PIPE_STREAM, "%s",
