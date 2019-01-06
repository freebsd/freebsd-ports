--- src/main.c.orig	2018-09-01 02:06:59 UTC
+++ src/main.c
@@ -395,6 +395,11 @@ main (int argc, char **argv)
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
@@ -402,11 +407,6 @@ main (int argc, char **argv)
                 log_message (LOG_WARNING,
                              "Not running as root, so not changing UID/GID.");
 
-        /* Create log file after we drop privileges */
-        if (setup_logging ()) {
-                exit (EX_SOFTWARE);
-        }
-
         if (child_pool_create () < 0) {
                 fprintf (stderr,
                          "%s: Could not create the pool of children.\n",
