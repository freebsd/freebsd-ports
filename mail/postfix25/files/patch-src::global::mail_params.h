--- src/global/mail_params.h.orig	Mon Jun 30 18:57:48 2008
+++ src/global/mail_params.h	Mon Jun 30 19:00:05 2008
@@ -67,7 +67,7 @@
 extern gid_t var_owner_gid;
 
 #define VAR_SGID_GROUP		"setgid_group"
-#define DEF_SGID_GROUP		"postdrop"
+#define DEF_SGID_GROUP		"maildrop"
 extern char *var_sgid_group;
 extern gid_t var_sgid_gid;
 
@@ -241,7 +241,7 @@
   */
 #define VAR_DAEMON_DIR		"daemon_directory"
 #ifndef DEF_DAEMON_DIR
-#define DEF_DAEMON_DIR		"/usr/libexec/postfix"
+#define DEF_DAEMON_DIR		"!!PREFIX!!/libexec/postfix"
 #endif
 extern char *var_daemon_dir;
 
@@ -265,7 +265,7 @@
   */
 #define VAR_DATA_DIR		"data_directory"
 #ifndef DEF_DATA_DIR
-#define DEF_DATA_DIR		"/var/lib/postfix"
+#define DEF_DATA_DIR		"/var/db/postfix"
 #endif
 extern char *var_data_dir;
 
@@ -279,7 +279,7 @@
   */
 #define VAR_CONFIG_DIR		"config_directory"
 #ifndef DEF_CONFIG_DIR
-#define DEF_CONFIG_DIR		"/etc/postfix"
+#define DEF_CONFIG_DIR		"!!PREFIX!!/etc/postfix"	
 #endif
 extern char *var_config_dir;
 
