
$FreeBSD$

--- modules/acc/acc_mod.c	2004/02/05 19:49:04	1.1
+++ modules/acc/acc_mod.c	2004/02/05 19:49:16
@@ -93,7 +93,7 @@
 int log_level=L_NOTICE;
 char *log_fmt=DEFAULT_LOG_FMT;
 #ifdef RAD_ACC
-char *radius_config = "/usr/local/etc/radiusclient/radiusclient.conf";
+char *radius_config = (CFG_DIR "radiusclient.conf");
 int radius_flag = 0;
 int radius_missed_flag = 0;
 int service_type = PW_SIP_SESSION;
