--- include/db.c.orig	Sun Feb 15 09:55:55 2004
+++ include/db.c	Sun Feb 15 09:56:53 2004
@@ -123,6 +123,10 @@
  */ 
 int	DBexecute(char *query)
 {
+#ifdef	HAVE_PGSQL
+	PGresult	*result;
+#endif
+
 /*	zabbix_set_log_level(LOG_LEVEL_DEBUG);*/
 	zabbix_log( LOG_LEVEL_DEBUG, "Executing query:%s",query);
 #ifdef	HAVE_MYSQL
@@ -138,8 +142,6 @@
 	}
 #endif
 #ifdef	HAVE_PGSQL
-	PGresult	*result;
-
 	result = PQexec(conn,query);
 
 	if( result==NULL)
@@ -168,6 +170,9 @@
  */ 
 DB_RESULT *DBselect(char *query)
 {
+#ifdef	HAVE_PGSQL
+	PGresult	*result;
+#endif
 /*	zabbix_set_log_level(LOG_LEVEL_DEBUG);*/
 	zabbix_log( LOG_LEVEL_DEBUG, "Executing query:%s",query);
 #ifdef	HAVE_MYSQL
@@ -185,8 +190,6 @@
 	return	mysql_store_result(&mysql);
 #endif
 #ifdef	HAVE_PGSQL
-	PGresult	*result;
-
 	result = PQexec(conn,query);
 
 	if( result==NULL)
