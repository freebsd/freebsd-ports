--- src/mysql.c.orig	Tue Jun 28 16:05:53 2005
+++ src/mysql.c	Tue Jun 28 16:18:17 2005
@@ -137,10 +137,11 @@
 _nss_mysql_set_options (sql_server_t *server)
 {
   DN ("_nss_mysql_set_options")
+  static const unsigned	def_timeout = DEF_TIMEOUT;
 
   DENTER
 
-  mysql_options(&ci.link, MYSQL_OPT_CONNECT_TIMEOUT, DEF_TIMEOUT);
+  mysql_options(&ci.link, MYSQL_OPT_CONNECT_TIMEOUT, &def_timeout);
   mysql_options(&ci.link, MYSQL_READ_DEFAULT_GROUP, "libnss-mysql");
 
   DEXIT
