--- ./libpkg/pkgdb.c.orig	2013-09-19 20:55:45.183234062 +0200
+++ ./libpkg/pkgdb.c	2013-09-19 20:55:15.578236583 +0200
@@ -2661,7 +2661,7 @@
 		return (EPKG_FATAL);
 	}
 
-	if ((ret = pkg_analyse_files(db, pkg)) == EPKG_OK) {
+	if ((ret = pkg_analyse_files(db, pkg, NULL)) == EPKG_OK) {
 		if (!db->prstmt_initialized &&
 		    prstmt_initialize(db) != EPKG_OK)
 			return (EPKG_FATAL);
