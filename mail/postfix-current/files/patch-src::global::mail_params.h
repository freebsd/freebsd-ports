--- src/global/mail_params.h.orig	2008-04-28 20:47:26.000000000 -0300
+++ src/global/mail_params.h	2008-07-20 20:21:07.000000000 -0300
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
 
