--- ./src/main.c.orig	2010-06-21 13:39:34.000000000 -0400
+++ ./src/main.c	2010-06-21 13:40:20.000000000 -0400
@@ -407,12 +407,9 @@
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
@@ -427,6 +424,13 @@
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
