--- ./mod_log_sql.h.orig	2007-08-06 00:03:47.000000000 +0800
+++ ./mod_log_sql.h	2007-08-06 00:52:49.000000000 +0800
@@ -67,7 +67,8 @@
 	LOGSQL_TABLE_NOTES,
 	LOGSQL_TABLE_HEADERSOUT,
 	LOGSQL_TABLE_HEADERSIN,
-	LOGSQL_TABLE_COOKIES
+	LOGSQL_TABLE_COOKIES,
+	LOGSQL_TABLE_SCORE
 } logsql_tabletype;
 
 /* All Tables */
@@ -96,6 +97,8 @@
 	/* create a SQL table named table_name of table_type */
 	logsql_table_ret (*create_table)(request_rec *r, logsql_dbconnection *db,
 		logsql_tabletype table_type, const char *table_name);
+        /* enclose an insert query with parameters to make it an insert ignore */
+        const char * (*enclose_insert_ignore)(const char* insert_query,request_rec *r);
 } logsql_dbdriver;
 
 LOGSQL_DECLARE(void) log_sql_register_driver(apr_pool_t *p,
