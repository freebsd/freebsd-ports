--- src/modules/db_unixodbc/connection.c.orig	2025-01-23 09:07:51 UTC
+++ src/modules/db_unixodbc/connection.c
@@ -179,14 +179,17 @@ err2:
 /*
  * Close the connection and release memory
  */
-void db_unixodbc_free_connection(struct my_con *con)
+void db_unixodbc_free_connection(struct pool_con *con)
 {
+	struct my_con *_c;
+
 	if(!con)
 		return;
-	SQLFreeHandle(SQL_HANDLE_ENV, con->env);
-	SQLDisconnect(con->dbc);
-	SQLFreeHandle(SQL_HANDLE_DBC, con->dbc);
-	pkg_free(con);
+	_c = (struct my_con *)con;
+	SQLFreeHandle(SQL_HANDLE_ENV, _c->env);
+	SQLDisconnect(_c->dbc);
+	SQLFreeHandle(SQL_HANDLE_DBC, _c->dbc);
+	pkg_free(_c);
 }
 
 
