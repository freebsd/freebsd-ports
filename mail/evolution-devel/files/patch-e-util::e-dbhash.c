
$FreeBSD$

--- e-util/e-dbhash.c	2001/12/06 10:25:50	1.1
+++ e-util/e-dbhash.c	2001/12/06 10:26:28
@@ -33,6 +33,7 @@
 	DB *db;
 	int rv;
 
+#if 0
 	int major, minor, patch;
 
 	db_version (&major, &minor, &patch);
@@ -43,6 +44,7 @@
 		g_warning ("Wrong version of libdb.");
 		return NULL;
 	}
+#endif
 
 	/* Attempt to open the database */
 	rv = db_create (&db, NULL, 0);
