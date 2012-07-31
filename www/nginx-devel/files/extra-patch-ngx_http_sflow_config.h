--- ../nginx-sflow-module-0.9.6/ngx_http_sflow_config.h.orig	2012-07-31 21:36:49.000000000 +0400
+++ ../nginx-sflow-module-0.9.6/ngx_http_sflow_config.h	2012-07-31 21:37:20.000000000 +0400
@@ -17,7 +17,7 @@
   -----------------___________________________------------------
 */
 
-#define SFWB_DEFAULT_CONFIGFILE "/etc/hsflowd.auto"
+#define SFWB_DEFAULT_CONFIGFILE "%%PREFIX%%/etc/hsflowd.auto"
 #define SFWB_SEPARATORS " \t\r\n="
 #define SFWB_QUOTES "'\" \t\r\n"
 /* SFWB_MAX LINE LEN must be enough to hold the whole list of targets */
