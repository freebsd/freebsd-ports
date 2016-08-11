--- src/http_auth.h.orig	2016-07-16 10:06:16 UTC
+++ src/http_auth.h
@@ -9,13 +9,15 @@
 # define USE_LDAP
 # include <ldap.h>
 #endif
+#include <mysql/mysql.h>
 
 typedef enum {
 	AUTH_BACKEND_UNSET,
 	AUTH_BACKEND_PLAIN,
 	AUTH_BACKEND_LDAP,
 	AUTH_BACKEND_HTPASSWD,
-	AUTH_BACKEND_HTDIGEST
+	AUTH_BACKEND_HTDIGEST,
+	AUTH_BACKEND_MYSQL
 } auth_backend_t;
 
 typedef struct {
@@ -50,6 +52,23 @@ typedef struct {
 	buffer *ldap_filter_pre;
 	buffer *ldap_filter_post;
 #endif
+
+	MYSQL  *mysql_conn;
+	buffer *auth_mysql_host;
+	buffer *auth_mysql_user;
+	buffer *auth_mysql_pass;
+	buffer *auth_mysql_db;
+	buffer *auth_mysql_port;
+	buffer *auth_mysql_socket;
+	buffer *auth_mysql_users_table;
+	buffer *auth_mysql_col_user;
+	buffer *auth_mysql_col_pass;
+	buffer *auth_mysql_col_realm;
+	buffer *auth_mysql_domains_table;
+	buffer *auth_mysql_col_domain;
+	buffer *auth_mysql_domains_table_col_domain_id;
+	buffer *auth_mysql_users_table_col_domain_id;
+
 } mod_auth_plugin_config;
 
 typedef struct {
