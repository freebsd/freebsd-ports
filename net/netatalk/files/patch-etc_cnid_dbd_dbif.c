--- etc/cnid_dbd/dbif.c.orig	Sat Jan 27 23:07:17 2007
+++ etc/cnid_dbd/dbif.c	Sat Jan 27 23:08:04 2007
@@ -514,7 +514,11 @@ int dbif_count(const int dbi, u_int32_t 
     DB_BTREE_STAT *sp;
     DB *db = db_table[dbi].db;
 
+#if DB_VERSION_MAJOR > 4 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR >= 3)
+    ret = db->stat(db, db_txn, &sp, 0);
+#else
     ret = db->stat(db, &sp, 0);
+#endif
 
     if (ret) {
         LOG(log_error, logtype_cnid, "error getting stat infotmation on database: %s", db_strerror(errno));
