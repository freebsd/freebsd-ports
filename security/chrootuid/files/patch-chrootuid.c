--- chrootuid.c.orig	Wed Jul 25 09:47:44 2001
+++ chrootuid.c	Sun Jun 23 15:06:10 2002
@@ -81,6 +81,10 @@
 	syslog(LOG_ERR, "usage: %s path user command", argv[0]);
 	return (0);
     }
+
+    syslog(LOG_NOTICE, "chrootuid: dir(%s) user(%s) command(%s)",
+	argv[1], argv[2], argv[3]);
+
     /* Must step into the new subtree. */
 
     if (chdir(argv[1])) {
