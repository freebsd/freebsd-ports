--- chrootuid.c.orig	2001-07-25 16:47:44 UTC
+++ chrootuid.c
@@ -81,6 +81,10 @@ char  **argv;
 	syslog(LOG_ERR, "usage: %s path user command", argv[0]);
 	return (0);
     }
+
+    syslog(LOG_NOTICE, "chrootuid: dir(%s) user(%s) command(%s)",
+	argv[1], argv[2], argv[3]);
+
     /* Must step into the new subtree. */
 
     if (chdir(argv[1])) {
