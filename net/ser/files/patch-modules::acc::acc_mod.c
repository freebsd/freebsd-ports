
$FreeBSD$

--- modules/acc/acc_mod.c.orig	Mon Jul 19 01:56:23 2004
+++ modules/acc/acc_mod.c	Tue Jul 27 21:01:36 2004
@@ -93,7 +93,7 @@
 int log_level=L_NOTICE;
 char *log_fmt=DEFAULT_LOG_FMT;
 #ifdef RAD_ACC
-static char *radius_config = "/usr/local/etc/radiusclient/radiusclient.conf";
+static char *radius_config = (CFG_DIR "radiusclient.conf");
 int radius_flag = 0;
 int radius_missed_flag = 0;
 static int service_type = -1;
