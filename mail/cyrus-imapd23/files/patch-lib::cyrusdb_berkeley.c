Index: lib/cyrusdb_berkeley.c
diff -u -p lib/cyrusdb_berkeley.c.orig lib/cyrusdb_berkeley.c
--- lib/cyrusdb_berkeley.c.orig	2009-03-10 11:56:22.000000000 +0900
+++ lib/cyrusdb_berkeley.c	2010-05-27 14:21:33.558155752 +0900
@@ -108,7 +108,7 @@ static void db_panic(DB_ENV *dbenv __att
     exit(EC_TEMPFAIL);
 }
 
-#if (DB_VERSION_MAJOR == 4) && (DB_VERSION_MINOR >= 3)
+#if (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 3) || DB_VERSION_MAJOR >= 5
 static void db_err(const DB_ENV *dbenv __attribute__((unused)),
 		   const char *db_prfx, const char *buffer)
 #else
@@ -164,7 +164,7 @@ static int init(const char *dbdir, int m
 #endif
     }
 
-#if (DB_VERSION_MAJOR == 4) && (DB_VERSION_MINOR >= 3)
+#if (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 3) || DB_VERSION_MAJOR >= 5
     dbenv->set_msgcall(dbenv, db_msg);
 #endif
     dbenv->set_errcall(dbenv, db_err);
@@ -282,7 +282,7 @@ static int mysync(void)
 
     assert(dbinit);
 
-#if !(DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 1)
+#if !((DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 1) || DB_VERSION_MAJOR >= 5)
     do {
 #endif
 #if (DB_VERSION_MAJOR > 3) || ((DB_VERSION_MAJOR == 3) && (DB_VERSION_MINOR > 0))
@@ -290,7 +290,7 @@ static int mysync(void)
 #else
 	r = txn_checkpoint(dbenv, 0, 0);
 #endif
-#if !(DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 1)
+#if !((DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 1) || DB_VERSION_MAJOR >= 5)
     } while (r == DB_INCOMPLETE);  /* Never returned by BDB 4.1 */
 #endif
     if (r) {
@@ -413,7 +413,7 @@ static int myopen(const char *fname, DBT
     /* xxx set comparator! */
     if (flags & CYRUSDB_MBOXSORT) db->set_bt_compare(db, mbox_compar);
 
-#if DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 1
+#if (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 1) || DB_VERSION_MAJOR >= 5
     r = (db->open)(db, NULL, fname, NULL, type, dbflags | DB_AUTO_COMMIT, 0664);
 #else
     r = (db->open)(db, fname, NULL, type, dbflags, 0664);
