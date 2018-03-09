--- sesman/session.c.orig	2017-12-27 14:40:24 UTC
+++ sesman/session.c
@@ -484,22 +484,40 @@ session_start_fork(tbus data, tui8 type,
          *  $OpenBSD: session.c,v 1.252 2010/03/07 11:57:13 dtucker Exp $
          *  with some ideas about BSD process grouping to xrdp
          */
+        pid_t bsdsespid = g_fork();
 
-        /**
-         * Create a new session and process group since the 4.4BSD
-         * setlogin() affects the entire process group
-         */
-        if (g_setsid() < 0)
+        if (bsdsespid == -1)
         {
-            log_message(LOG_LEVEL_ERROR,
-                        "setsid failed - pid %d", g_getpid());
+        }
+        else if (bsdsespid == 0) /* BSD session leader */
+        {
+            /**
+             * Create a new session and process group since the 4.4BSD
+             * setlogin() affects the entire process group
+             */
+            if (g_setsid() < 0)
+            {
+                log_message(LOG_LEVEL_ERROR,
+                            "setsid failed - pid %d", g_getpid());
+            }
+
+            if (g_setlogin(s->username) < 0)
+            {
+                log_message(LOG_LEVEL_ERROR,
+                            "setlogin failed for user %s - pid %d", s->username,
+                            g_getpid());
+            }
         }
 
-        if (g_setlogin(s->username) < 0)
+        g_waitpid(bsdsespid);
+
+        if (bsdsespid > 0)
         {
-            log_message(LOG_LEVEL_ERROR,
-                        "setlogin failed for user %s - pid %d", s->username,
-                        g_getpid());
+            g_exit(0);
+            /*
+             * intermediate sesman should exit here after WM exits.
+             * do not execure the following codes.
+             */
         }
 #endif
         window_manager_pid = g_fork(); /* parent becomes X,
