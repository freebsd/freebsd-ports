--- src/sql.c.orig	Tue Sep 19 17:14:21 2000
+++ src/sql.c	Mon Oct 13 09:59:28 2003
@@ -204,7 +204,8 @@
 #define unlock_url(db)	sql_query(db,"UNLOCK TABLES")
 
 static int InitDB(DB*db){
-	if (!(mysql_connect(&(db->mysql),DBHost,DBUser,DBPass))){
+	mysql_init(&(db->mysql));
+	if (!(mysql_real_connect(&(db->mysql),DBHost,DBUser,DBPass,DB_DEFAULT,0,NULL,0))){
 		db->errcode=1;
 		return(1);
 	}
