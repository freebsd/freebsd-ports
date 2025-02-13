--- src/modules/db_unixodbc/connection.h.orig	2025-01-23 09:07:51 UTC
+++ src/modules/db_unixodbc/connection.h
@@ -83,7 +83,7 @@ struct my_con *db_unixodbc_new_connection(struct db_id
 /*
  * Close the connection and release memory
  */
-void db_unixodbc_free_connection(struct my_con *con);
+void db_unixodbc_free_connection(struct pool_con *con);
 
 char *db_unixodbc_build_conn_str(const struct db_id *id, char *buf);
 
