--- res/res_watchdog.c.orig	Fri Jul 15 13:24:24 2005
+++ res/res_watchdog.c	Fri Jul 15 13:24:42 2005
@@ -40,6 +40,10 @@
 
 /* Registrar for operations */
 
+#ifndef O_SYNC
+#define O_SYNC O_FSYNC
+#endif
+
 static struct watchdog_pvt *watchdogs = NULL;
 
 STANDARD_LOCAL_USER;
