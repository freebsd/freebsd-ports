--- res/res_watchdog.c.orig	Mon Jan 23 23:55:25 2006
+++ res/res_watchdog.c	Mon Jan 23 23:55:10 2006
@@ -37,6 +37,10 @@
 #include <asterisk/utils.h>
 #include <asterisk/adsi.h>
 
+#if defined(__FreeBSD__) && !defined(O_SYNC)
+#define O_SYNC O_FSYNC
+#endif
+
 static struct watchdog_pvt *watchdogs = NULL;
 
 STANDARD_LOCAL_USER;
