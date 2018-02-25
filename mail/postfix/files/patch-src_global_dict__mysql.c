# PR: 220224 fix build against mysql 8.x
#
# from https://dev.mysql.com/doc/refman/5.7/en/mysql-options.html
# o MYSQL_OPT_SSL_VERIFY_SERVER_CERT (argument type: my_bool *)
#    This option is deprecated as of MySQL 5.7.11 and is removed in MySQL 8.0.
#    Instead, use MYSQL_OPT_SSL_MODE with a value of SSL_MODE_VERIFY_IDENTITY. 
#
--- src/global/dict_mysql.c.orig	2017-02-19 01:58:20 UTC
+++ src/global/dict_mysql.c
@@ -656,7 +656,11 @@ static void plmysql_connect_single(DICT_
 		      dict_mysql->tls_key_file, dict_mysql->tls_cert_file,
 		      dict_mysql->tls_CAfile, dict_mysql->tls_CApath,
 		      dict_mysql->tls_ciphers);
-#if MYSQL_VERSION_ID >= 50023
+#if MYSQL_VERSION_ID >= 80000 && !defined(MARIADB_VERSION_ID)
+    if (dict_mysql->tls_verify_cert != -1)
+	mysql_options(host->db, MYSQL_OPT_SSL_MODE,
+		      &dict_mysql->tls_verify_cert);
+#elif MYSQL_VERSION_ID >= 50023
     if (dict_mysql->tls_verify_cert != -1)
 	mysql_options(host->db, MYSQL_OPT_SSL_VERIFY_SERVER_CERT,
 		      &dict_mysql->tls_verify_cert);
