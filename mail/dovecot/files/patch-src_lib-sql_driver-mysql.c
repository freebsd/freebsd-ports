--- src/lib-sql/driver-mysql.c.orig	2018-11-23 11:06:45 UTC
+++ src/lib-sql/driver-mysql.c
@@ -173,7 +173,9 @@ static int driver_mysql_connect(struct sql_db *_db)
 static void driver_mysql_disconnect(struct sql_db *_db)
 {
 	struct mysql_db *db = (struct mysql_db *)_db;
-	mysql_close(db->mysql);
+	if (db->mysql != NULL)
+		mysql_close(db->mysql);
+	db->mysql = NULL;
 }
 
 static int driver_mysql_parse_connect_string(struct mysql_db *db,
@@ -311,7 +313,9 @@ static void driver_mysql_deinit_v(struct sql_db *_db)
 	_db->no_reconnect = TRUE;
 	sql_db_set_state(&db->api, SQL_DB_STATE_DISCONNECTED);
 
-	mysql_close(db->mysql);
+	if (db->mysql != NULL)
+		mysql_close(db->mysql);
+	db->mysql = NULL;
 
 	sql_connection_log_finished(_db);
 	event_unref(&_db->event);
