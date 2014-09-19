--- src/sgDb.c.orig	2008-07-14 20:29:41.000000000 +0200
+++ src/sgDb.c	2014-01-14 11:53:55.712138134 +0100
@@ -119,14 +119,39 @@
     flag = DB_CREATE;
     if(createdb)
       flag = flag | DB_TRUNCATE;
-    if ((ret =
-         Db->dbp->open(Db->dbp, NULL, dbfile, NULL, DB_BTREE, flag, 0664)) != 0) {
+    if ((ret = Db->dbp->open(Db->dbp,
+#if DB_VERSION_MINOR >= 1
+	NULL,
+#endif
+	dbfile, NULL, DB_BTREE, flag, 0664)) != 0) {
+      (void) Db->dbp->close(Db->dbp, 0);
+      sgLogFatalError("Error db_open: %s", strerror(ret));
+    }
+  } else {
+    if ((ret = Db->dbp->open(Db->dbp,
+#if DB_VERSION_MINOR >= 1
+	NULL,
+#endif
+	dbfile, NULL, DB_BTREE, DB_CREATE, 0664)) != 0) {
+      sgLogFatalError("Error db_open: %s", strerror(ret));
+    }
+  }
+#endif
+#if DB_VERSION_MAJOR >= 5
+  if(globalUpdate || createdb || (dbfile != NULL && stat(dbfile,&st))){
+    flag = DB_CREATE;
+    if(createdb)
+      flag = flag | DB_TRUNCATE;
+    if ((ret = Db->dbp->open(Db->dbp,
+	NULL,
+	dbfile, NULL, DB_BTREE, flag, 0664)) != 0) {
       (void) Db->dbp->close(Db->dbp, 0);
       sgLogFatalError("Error db_open: %s", strerror(ret));
     }
   } else {
-    if ((ret =
-         Db->dbp->open(Db->dbp, NULL, dbfile, NULL, DB_BTREE, DB_CREATE, 0664)) != 0) {
+    if ((ret = Db->dbp->open(Db->dbp,
+	NULL,
+	dbfile, NULL, DB_BTREE, DB_CREATE, 0664)) != 0) {
       sgLogFatalError("Error db_open: %s", strerror(ret));
     }
   }
