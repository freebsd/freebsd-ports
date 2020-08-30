--- src/main.c.orig	2018-09-01 00:55:39 UTC
+++ src/main.c
@@ -395,17 +395,17 @@ main (int argc, char **argv)
                 }
         }
 
+        /* Create log file before we drop privileges */
+        if (setup_logging ()) {
+                exit (EX_SOFTWARE);
+        }
+
         /* Switch to a different user if we're running as root */
         if (geteuid () == 0)
                 change_user (argv[0]);
         else
                 log_message (LOG_WARNING,
                              "Not running as root, so not changing UID/GID.");
-
-        /* Create log file after we drop privileges */
-        if (setup_logging ()) {
-                exit (EX_SOFTWARE);
-        }
 
         if (child_pool_create () < 0) {
                 fprintf (stderr,
