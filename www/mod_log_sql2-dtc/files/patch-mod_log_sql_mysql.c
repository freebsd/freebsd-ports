--- ./mod_log_sql_mysql.c.orig	2007-08-06 00:55:32.000000000 +0800
+++ ./mod_log_sql_mysql.c	2007-08-06 00:52:59.000000000 +0800
@@ -250,6 +250,10 @@
 	return LOGSQL_TABLE_SUCCESS;
 }
 
+static char *make_mysql_ignore_insert(char * insert_query, request_rec *r) {
+	return apr_psprintf(r->pool, "insert ignore into %s ;",insert_query);
+}
+
 static const char *supported_drivers[] = {"mysql",NULL};
 static logsql_dbdriver mysql_driver = {
     "mysql",
@@ -258,7 +262,8 @@
 	log_sql_mysql_close,	/* close DB connection */
 	log_sql_mysql_escape,	/* escape query */
 	log_sql_mysql_query,	/* insert query */
-	log_sql_mysql_create	/* create table */
+	log_sql_mysql_create,	/* create table */
+	make_mysql_ignore_insert /* insert ignore */
 };
 
 LOGSQL_REGISTER(mysql) {
