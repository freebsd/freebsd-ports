# PR: 220224 fix build against mysql 8.x
#
# from https://dev.mysql.com/doc/refman/5.7/en/mysql-options.html
# o MYSQL_OPT_SSL_VERIFY_SERVER_CERT (argument type: my_bool *)
#    This option is deprecated as of MySQL 5.7.11 and is removed in MySQL 8.0.
#    Instead, use MYSQL_OPT_SSL_MODE with a value of SSL_MODE_VERIFY_IDENTITY. 
#
--- src/global/dict_mysql.c.orig	2017-02-19 01:58:20 UTC
+++ src/global/dict_mysql.c
@@ -198,6 +198,15 @@
 
 #include "dict_mysql.h"
 
+/* MySQL 8.x API change */
+
+#if MYSQL_VERSION_ID >= 80000 && !defined(MARIADB_BASE_VERSION)
+#define DICT_MYSQL_SSL_VERIFY_SERVER_CERT MYSQL_OPT_SSL_MODE
+#elif MYSQL_VERSION_ID >= 50023
+#define DICT_MYSQL_SSL_VERIFY_SERVER_CERT MYSQL_OPT_SSL_VERIFY_SERVER_CERT
+#endif
+
+
 /* need some structs to help organize things */
 typedef struct {
     MYSQL  *db;
@@ -237,7 +246,7 @@ typedef struct {
     char   *tls_CAfile;
     char   *tls_CApath;
     char   *tls_ciphers;
-#if MYSQL_VERSION_ID >= 50023
+#if defined(DICT_MYSQL_SSL_VERIFY_SERVER_CERT)
     int     tls_verify_cert;
 #endif
 #endif
@@ -656,9 +665,9 @@ static void plmysql_connect_single(DICT_
 		      dict_mysql->tls_key_file, dict_mysql->tls_cert_file,
 		      dict_mysql->tls_CAfile, dict_mysql->tls_CApath,
 		      dict_mysql->tls_ciphers);
-#if MYSQL_VERSION_ID >= 50023
+#if defined(DICT_MYSQL_SSL_VERIFY_SERVER_CERT)
     if (dict_mysql->tls_verify_cert != -1)
-	mysql_options(host->db, MYSQL_OPT_SSL_VERIFY_SERVER_CERT,
+         mysql_options(host->db, DICT_MYSQL_SSL_VERIFY_SERVER_CERT,
 		      &dict_mysql->tls_verify_cert);
 #endif
 #endif
@@ -723,7 +732,7 @@ static void mysql_parse_config(DICT_MYSQ
     dict_mysql->tls_CAfile = cfg_get_str(p, "tls_CAfile", NULL, 0, 0);
     dict_mysql->tls_CApath = cfg_get_str(p, "tls_CApath", NULL, 0, 0);
     dict_mysql->tls_ciphers = cfg_get_str(p, "tls_ciphers", NULL, 0, 0);
-#if MYSQL_VERSION_ID >= 50023
+#if defined(DICT_MYSQL_SSL_VERIFY_SERVER_CERT)
     dict_mysql->tls_verify_cert = cfg_get_bool(p, "tls_verify_cert", -1);
 #endif
 #endif
