--- ./scanner.c.orig	2013-11-02 05:06:41.000000000 +0400
+++ ./scanner.c	2013-11-13 17:25:27.000000000 +0400
@@ -590,7 +590,7 @@
 
 sql_failed:
 	if( ret != SQLITE_OK )
-		fprintf(stderr, "Error creating SQLite3 database!\n");
+    DPRINTF(E_ERROR, L_DB_SQL, "Error creating SQLite3 database!\n");
 	return (ret != SQLITE_OK);
 }
 
