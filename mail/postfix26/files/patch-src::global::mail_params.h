--- src/global/mail_params.h.orig	Fri Feb 11 21:53:21 2005
+++ src/global/mail_params.h	Sat Mar  5 11:53:42 2005
@@ -64,7 +64,7 @@
 extern gid_t var_owner_gid;
 
 #define VAR_SGID_GROUP		"setgid_group"
-#define DEF_SGID_GROUP		"postdrop"
+#define DEF_SGID_GROUP		"maildrop"
 extern char *var_sgid_group;
 extern gid_t var_sgid_gid;
 
@@ -221,7 +221,7 @@
   */
 #define VAR_DAEMON_DIR		"daemon_directory"
 #ifndef DEF_DAEMON_DIR
-#define DEF_DAEMON_DIR		"/usr/libexec/postfix"
+#define DEF_DAEMON_DIR		"!!PREFIX!!/libexec/postfix"
 #endif
 extern char *var_daemon_dir;
 
@@ -250,7 +250,7 @@
   */
 #define VAR_CONFIG_DIR		"config_directory"
 #ifndef DEF_CONFIG_DIR
-#define DEF_CONFIG_DIR		"/etc/postfix"
+#define DEF_CONFIG_DIR		"!!PREFIX!!/etc/postfix"
 #endif
 extern char *var_config_dir;
 
