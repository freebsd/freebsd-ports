--- ./pkg/create.c.orig	2012-12-21 05:57:15.000000000 -0600
+++ ./pkg/create.c	2013-01-13 12:16:18.129456852 -0600
@@ -73,7 +73,7 @@
 	    PKG_LOAD_CATEGORIES | PKG_LOAD_DIRS | PKG_LOAD_SCRIPTS |
 	    PKG_LOAD_OPTIONS | PKG_LOAD_MTREE | PKG_LOAD_LICENSES |
 	    PKG_LOAD_USERS | PKG_LOAD_GROUPS | PKG_LOAD_SHLIBS;
-	const char *format;
+	const char *format = NULL;
 	bool foundone;
 
 	if (pkgdb_open(&db, PKGDB_DEFAULT) != EPKG_OK) {
