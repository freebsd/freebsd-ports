--- get_opt.c.orig	2013-11-15 10:28:02 UTC
+++ get_opt.c
@@ -5,6 +5,33 @@
 #include <string.h>
 #include "vars.h"
 
+int sections_count;
+char *chg_log;
+FILE *change_log;
+
+char **work_id;
+int work_id_count;
+int work_id_flag;
+
+char **allow_id;
+int allow_id_count;
+
+char *work_ip;
+int work_ip_count;
+int work_ip_flag;
+
+char *allow_ip;
+int allow_ip_count;
+
+int write_hostname_to_log;
+char *makecache;
+char *err_log;
+char *allow_urls_file;
+
+char **change_from;
+char **change_to;
+int change_count;
+int raw_change_log_flag;
 
 void get_opt(char* config_file)
 {
