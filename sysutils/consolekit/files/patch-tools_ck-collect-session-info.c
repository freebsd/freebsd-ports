--- tools/ck-collect-session-info.c.orig	2009-04-29 15:07:29.000000000 -0400
+++ tools/ck-collect-session-info.c	2010-07-12 23:55:13.000000000 -0400
@@ -226,6 +226,12 @@ fill_x11_info (SessionInfo *si)
         gboolean       res;
         CkProcessStat *xorg_stat;
         GError        *error;
+        char          *err;
+        char          *out;
+        int            status;
+        int            i;
+        char          *argv[4];
+        GPtrArray     *env;
 
         /* assume this is true then check it */
         si->x11_display = ck_unix_pid_get_env (si->pid, "DISPLAY");
@@ -272,6 +278,52 @@ fill_x11_info (SessionInfo *si)
         }
 
         si->x11_display_device = ck_process_stat_get_tty (xorg_stat);
+        if (g_strcmp0 (si->x11_display_device, si->display_device) != 0) {
+                goto gotit;
+        }
+
+        g_free (si->x11_display_device);
+
+        /* get the applicable environment */
+        env = get_filtered_environment (si->pid);
+
+        argv[0] = LIBEXECDIR "/ck-get-x11-display-device";
+        argv[1] = NULL;
+
+        error = NULL;
+        out = NULL;
+        err = NULL;
+        status = -1;
+        res = g_spawn_sync (NULL,
+                            argv,
+                            (char **)env->pdata,
+                            0,
+                            (GSpawnChildSetupFunc)setuid_child_setup_func,
+                            si,
+                            &out,
+                            &err,
+                            &status,
+                            &error);
+        for (i = 0; i < env->len; i++) {
+                g_free (g_ptr_array_index (env, i));
+        }
+        g_ptr_array_free (env, TRUE);
+
+        if (error != NULL) {
+                g_warning ("Unable to get display device for x11 server: %s", error->message);
+                g_error_free (error);
+        }
+
+        if (status == 0) {
+                if (res && out != NULL) {
+                        si->x11_display_device = g_strstrip (out);
+                        goto gotit;
+                }
+        }
+
+        si->x11_display_device = ck_process_stat_get_tty (xorg_stat);
+
+gotit:
         ck_process_stat_free (xorg_stat);
 
         si->is_local = TRUE;
@@ -410,5 +462,5 @@ main (int    argc,
 
         ret = collect_session_info (user_id, process_id);
 
-	return ret != TRUE;
+        return ret != TRUE;
 }
