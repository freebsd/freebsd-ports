--- src/sql.c.orig	Tue Aug  1 19:17:38 2006
+++ src/sql.c	Tue Aug  1 19:18:11 2006
@@ -200,7 +200,7 @@
 	db=(DB*)Indexer->db;
 	db->mysql.port=Indexer->Conf->DBPort;
 	db->mysql.unix_socket="/var/tmp/xxx";
-	if (!(mysql_connect(&(db->mysql),Indexer->Conf->DBHost,Indexer->Conf->DBUser,Indexer->Conf->DBPass))){
+	if (!(mysql_real_connect(&(db->mysql),Indexer->Conf->DBHost,Indexer->Conf->DBUser,Indexer->Conf->DBPass,NULL,0,NULL,0))){
 		db->errcode=1;
 		return(1);
 	}
