--- src/modules/db_sqlite/dbase.c.orig	2025-01-23 09:07:51 UTC
+++ src/modules/db_sqlite/dbase.c
@@ -126,14 +126,17 @@ db1_con_t *db_sqlite_init(const str *_url)
  * No function should be called after this
  */
 
-static void db_sqlite_free_connection(struct sqlite_connection *con)
+static void db_sqlite_free_connection(struct pool_con *con)
 {
+	struct sqlite_connection *_c;
+
 	if(!con)
 		return;
+	_c = (struct sqlite_connection *)con;
 
-	sqlite3_close(con->conn);
-	free_db_id(con->hdr.id);
-	pkg_free(con);
+	sqlite3_close(_c->conn);
+	free_db_id(_c->hdr.id);
+	pkg_free(_c);
 }
 
 void db_sqlite_close(db1_con_t *_h)
