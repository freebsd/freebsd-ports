--- ./mod_log_sql_pgsql.c.orig	2007-08-06 00:55:44.000000000 +0800
+++ ./mod_log_sql_pgsql.c	2007-08-06 00:52:55.000000000 +0800
@@ -235,6 +235,10 @@
 	return LOGSQL_TABLE_SUCCESS;
 }
 
+static char *make_pgsql_ignore_insert(char * insert_query, request_rec *r) {
+	return apr_psprintf(r->pool, "begin ; insert into %s ; commit ;",insert_query);
+}
+
 static char *supported_drivers[] = {"pgsql",NULL};
 static logsql_dbdriver pgsql_driver = {
 	supported_drivers,
@@ -242,7 +246,8 @@
 	log_sql_pgsql_close,	/* close DB connection */
 	log_sql_pgsql_escape,	/* escape query */
 	log_sql_pgsql_query,	/* insert query */
-	log_sql_pgsql_create	/* create table */
+	log_sql_pgsql_create,	/* create table */
+	make_pgsql_ignore_insert /* insert ignore statement */
 };
 
 LOGSQL_REGISTER(pgsql) {
