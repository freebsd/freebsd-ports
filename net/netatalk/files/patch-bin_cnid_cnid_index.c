--- bin/cnid/cnid_index.c.orig	Sat Jan 27 23:03:04 2007
+++ bin/cnid/cnid_index.c	Sat Jan 27 23:04:51 2007
@@ -274,7 +274,11 @@ static int dbif_count(const int dbi, u_i
     DB_BTREE_STAT *sp;
     DB *db = db_table[dbi].db;
 
+#if DB_VERSION_MAJOR > 4 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 3)
+    ret = db->stat(db, db_txn, &sp, 0);
+#else
     ret = db->stat(db, &sp, 0);
+#endif
 
     if (ret) {
         LOG(log_error, logtype_cnid, "error getting stat infotmation on database: %s", db_strerror(errno));
