--- ./dkim-filter/dkim-db.c.orig	2008-03-05 02:41:25.000000000 +0900
+++ ./dkim-filter/dkim-db.c	2008-03-12 23:57:52.000000000 +0900
@@ -46,15 +46,22 @@
 	int flags = 0;
 #endif /* DB_VERSION_CHECK(2,0,0) */
 	int status = 0;
+	DBTYPE dbtype;
 
 	assert(db != NULL);
 	assert(file != NULL);
 
 #if DB_VERSION_CHECK(2,0,0)
 	if (ro)
+	{
 		flags |= DB_RDONLY;
+		dbtype = DB_UNKNOWN;
+	}
 	else
+	{
 		flags |= DB_CREATE;
+		dbtype = DB_BTREE;
+	}
 #endif /* DB_VERSION_CHECK(2,0,0) */
 
 #if DB_VERSION_CHECK(3,0,0)
@@ -62,21 +69,21 @@
 	if (status == 0)
 	{
 # if DB_VERSION_CHECK(4,1,25)
-		status = (*db)->open(*db, NULL, file, NULL, DB_UNKNOWN,
+		status = (*db)->open((*db), NULL, file, NULL, dbtype,
 		                     flags, 0);
 # else /* DB_VERSION_CHECK(4,1,25) */
-		status = (*db)->open(*db, file, NULL, DB_UNKNOWN,
-		                     flags, 0);
+		status = (*db)->open((*db), file, NULL, dbtype, flags, 0);
 # endif /* DB_VERSION_CHECK(4,1,25) */
 	}
 #elif DB_VERSION_CHECK(2,0,0)
-	status = db_open(file, DB_HASH, flags, DB_MODE, NULL, NULL, db);
+	status = db_open(file, dbtype, flags, DB_MODE, NULL, NULL, db);
 #else /* DB_VERSION_MAJOR < 2 */
 	*db = dbopen(file, (ro ? O_RDONLY :(O_CREAT|O_RDWR)), DB_MODE,
-	             DB_HASH, NULL);
+	             dbtype, NULL);
 	if (*db == NULL)
 		status = errno;
 #endif /* DB_VERSION_CHECK */
+
 	return status;
 }
 
