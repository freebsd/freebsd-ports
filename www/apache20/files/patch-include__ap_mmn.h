--- ./include/ap_mmn.h.orig	2010-10-21 05:47:06.975621911 +0000
+++ ./include/ap_mmn.h	2010-10-21 05:48:25.311622079 +0000
@@ -88,12 +88,15 @@
  * 20020903.12 (2.0.56-dev) added ap_get_server_revision / ap_version_t
  * 20020903.13 (2.0.62-dev) Add *ftp_directory_charset to proxy_dir_conf
  * 20020903.14 (2.0.64-dev) added ap_vhost_iterate_given_conn
+ * 20050127.0  (2.1.3-dev)  renamed regex_t->ap_regex_t, regmatch_t->ap_regmatch_t,
+ *                          REG_*->AP_REG_*, removed reg* in place of ap_reg*;
+ *                          added ap_regex.h
  */
 
 #define MODULE_MAGIC_COOKIE 0x41503230UL /* "AP20" */
 
 #ifndef MODULE_MAGIC_NUMBER_MAJOR
-#define MODULE_MAGIC_NUMBER_MAJOR 20020903
+#define MODULE_MAGIC_NUMBER_MAJOR 20050127
 #endif
 #define MODULE_MAGIC_NUMBER_MINOR 14                    /* 0...n */
 
