--- sesman/session.c.orig	2013-10-24 03:58:40.958300769 +0000
+++ sesman/session.c	2013-10-24 04:24:10.688299377 +0000
@@ -422,6 +422,35 @@
     g_sprintf(geometry, "%dx%d", width, height);
     g_sprintf(depth, "%d", bpp);
     g_sprintf(screen, ":%d", display);
+#ifdef __FreeBSD__
+    /*
+     * Create a new session and process group since 4.4BSD
+     * setlogin affects the entire process group.
+     *
+     * from: OpenBSD: session.c,v 1.252 2010/03/07 11:57:13 dtucker Exp
+     */
+    pid_t bsdsespid = g_fork();
+
+    if (bsdsespid == -1)
+    {
+    }
+    else if (bsdsespid == 0) /* BSD session leader */
+    {
+        if (setsid() < 0)
+        {
+          log_message(LOG_LEVEL_ERROR,
+            "setsid failed - pid %d", g_getpid());
+        }
+
+        if (setlogin(username) < 0)
+        {
+          log_message(LOG_LEVEL_ERROR,
+            "setlogin failed for user %s - pid %d", username, g_getpid());
+        }
+    }
+
+    g_waitpid(bsdsespid);
+#endif
     wmpid = g_fork();
     if (wmpid == -1)
     {
