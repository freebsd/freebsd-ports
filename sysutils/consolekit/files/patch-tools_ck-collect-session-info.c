$OpenBSD: patch-tools_ck-collect-session-info_c,v 1.1 2011/04/28 13:08:33 ajacoutot Exp $

XXX revert 4f88228f31a63c026c424a92827f26ad7535275c
The Kit people assume the world runs Linux and PAM, see
https://bugs.freedesktop.org/show_bug.cgi?id=28377
--- tools/ck-collect-session-info.c.orig	2013-08-10 20:47:52.000000000 +0200
+++ tools/ck-collect-session-info.c	2013-08-10 20:47:33.000000000 +0200
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
@@ -272,9 +278,56 @@ fill_x11_info (SessionInfo *si)
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
 
-        /* don't set is-local here - let the daemon do that */
+        si->is_local = TRUE;
+        si->is_local_is_set = TRUE;
 
         g_free (si->remote_host_name);
         si->remote_host_name = NULL;
@@ -303,6 +356,13 @@ fill_session_info (SessionInfo *si)
 
         fill_x11_info (si);
 
+        if (! si->is_local_is_set) {
+                /* FIXME: how should we set this? */
+                /* non x11 sessions must be local I guess */
+                si->is_local = TRUE;
+                si->is_local_is_set = TRUE;
+        }
+
         res = ck_unix_pid_get_login_session_id (si->pid, &si->login_session_id);
         if (! res) {
                 si->login_session_id = NULL;
