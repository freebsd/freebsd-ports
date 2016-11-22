--- src/main.c.orig	2014-12-13 00:57:23 UTC
+++ src/main.c
@@ -417,12 +417,9 @@ main (int argc, char **argv)
                 exit (EX_OSERR);
         }
 
-        /* Switch to a different user if we're running as root */
-        if (geteuid () == 0)
-                change_user (argv[0]);
-        else
-                log_message (LOG_WARNING,
-                             "Not running as root, so not changing UID/GID.");
+	/* To get this to run correctly on FreeBSD, we must
+	   create the PID and log files before we drop privileges.
+	   Other ideas are welcome */
 
         /* Create log file after we drop privileges */
         if (setup_logging ()) {
@@ -438,6 +435,13 @@ main (int argc, char **argv)
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
                          "%s: Could not create the pool of children.\n",
