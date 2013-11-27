--- ./metadata.c.orig	2013-11-02 05:06:41.000000000 +0400
+++ ./metadata.c	2013-11-13 17:25:27.000000000 +0400
@@ -183,7 +183,7 @@
 	strcat(file, ".srt");
 	if( access(file, R_OK) == 0 )
 	{
-		sql_exec(db, "INSERT into CAPTIONS"
+		sql_exec(db, "INSERT OR REPLACE into CAPTIONS"
 		             " (ID, PATH) "
 		             "VALUES"
 		             " (%lld, %Q)", detailID, file);
@@ -492,7 +492,7 @@
 	                   m.dlna_pn, song.mime?song.mime:m.mime, album_art);
 	if( ret != SQLITE_OK )
 	{
-		fprintf(stderr, "Error inserting details for '%s'!\n", path);
+    DPRINTF(E_ERROR, L_DB_SQL, "Error inserting details for '%s'!\n", path);
 		ret = 0;
 	}
 	else
@@ -675,7 +675,7 @@
 	                   m.rotation, thumb, m.creator, m.dlna_pn, m.mime);
 	if( ret != SQLITE_OK )
 	{
-		fprintf(stderr, "Error inserting details for '%s'!\n", path);
+    DPRINTF(E_ERROR, L_DB_SQL, "Error inserting details for '%s'!\n", path);
 		ret = 0;
 	}
 	else
@@ -1587,7 +1587,7 @@
                            m.mime, album_art);
 	if( ret != SQLITE_OK )
 	{
-		fprintf(stderr, "Error inserting details for '%s'!\n", path);
+    DPRINTF(E_ERROR, L_DB_SQL, "Error inserting details for '%s'!\n", path);
 		ret = 0;
 	}
 	else
