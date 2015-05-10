--- src/main.c.orig	2011-08-16 12:14:34 UTC
+++ src/main.c
@@ -407,12 +407,9 @@ main (int argc, char **argv)
                 exit (EX_OSERR);
         }
 
-        /* Switch to a different user if we're running as root */
-        if (geteuid () == 0)
-                change_user (argv[0]);
-        else
-                log_message (LOG_WARNING,
-                             "Not running as root, so not changing UID/GID.");
+	/*To get this to run correctly on FreeBSD, we must
+	  ceate the PID and log files before we drop privileges. 
+	  Other ideas are welcome */
 
         /* Create log file after we drop privileges */
         if (setup_logging ()) {
@@ -427,6 +424,13 @@ main (int argc, char **argv)
                         exit (EX_OSERR);
                 }
         }
+        /* Switch to a different user if we're running as root */
+        if (geteuid () == 0)
+                change_user (argv[0]);
+        else
+                log_message (LOG_WARNING,
+                             "Not running as root, so not changing UID/GID.");
+
 
         if (child_pool_create () < 0) {
                 fprintf (stderr,
