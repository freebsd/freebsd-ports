
$FreeBSD$

--- modules/acc/acc_mod.c	2003/07/06 18:04:54	1.1
+++ modules/acc/acc_mod.c	2003/07/06 18:05:26
@@ -92,7 +92,7 @@
 int log_level=L_NOTICE;
 char *log_fmt=DEFAULT_LOG_FMT;
 #ifdef RAD_ACC
-char *radius_config = "/usr/local/etc/radiusclient/radiusclient.conf";
+char *radius_config = (CFG_DIR "radiusclient.conf");
 int radius_flag = 0;
 int radius_missed_flag = 0;
 int service_type = PW_SIP;
