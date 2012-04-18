--- ./libpkg/pkgdb.c.orig	2012-04-13 22:16:54.000000000 +0200
+++ ./libpkg/pkgdb.c	2012-04-18 23:22:48.794371806 +0200
@@ -302,7 +302,7 @@
 	}
 
 	while (db_version < DBVERSION) {
-		if (!sqlite3_db_readonly(db->sqlite, "main")) {
+		if (sqlite3_db_readonly(db->sqlite, "main")) {
 			pkg_emit_error("The database is outdated and opened readonly");
 			return (EPKG_FATAL);
 		}
