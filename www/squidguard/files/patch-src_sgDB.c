--- src/sgDb.c.orig	Mon May 14 08:40:12 2001
+++ src/sgDb.c	Thu Dec 29 23:31:32 2005
@@ -97,14 +97,20 @@
     flag = DB_CREATE;
     if(createdb)
       flag = flag | DB_TRUNCATE;
-    if ((ret = 
-	 Db->dbp->open(Db->dbp, dbfile, NULL, DB_BTREE, flag, 0664)) != 0) {
+    if ((ret = Db->dbp->open(Db->dbp,
+#if DB_VERSION_MAJOR * 10 + DB_VERSION_MINOR >= 41
+	 NULL,
+#endif
+	 dbfile, NULL, DB_BTREE, flag, 0664)) != 0) {
       (void) Db->dbp->close(Db->dbp, 0);
       sgLogFatalError("Error db_open: %s", strerror(ret));
     }
   } else {
-    if ((ret = 
-	 Db->dbp->open(Db->dbp, dbfile, NULL, DB_BTREE, DB_CREATE, 0664)) != 0) {
+    if ((ret = Db->dbp->open(Db->dbp,
+#if DB_VERSION_MAJOR * 10 + DB_VERSION_MINOR >= 41
+	 NULL,
+#endif
+	 dbfile, NULL, DB_BTREE, DB_CREATE, 0664)) != 0) {
       sgLogFatalError("Error db_open: %s", strerror(ret));
     }
   }
