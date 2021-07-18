--- src/main.c.orig	2021-04-16 12:31:11 UTC
+++ src/main.c
@@ -377,17 +377,17 @@ main (int argc, char **argv)
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
                 log_message (LOG_INFO,
                              "Not running as root, so not changing UID/GID.");
-
-        /* Create log file after we drop privileges */
-        if (setup_logging ()) {
-                exit (EX_SOFTWARE);
-        }
 
         /* These signals are only for the parent process. */
         log_message (LOG_INFO, "Setting the various signals.");
