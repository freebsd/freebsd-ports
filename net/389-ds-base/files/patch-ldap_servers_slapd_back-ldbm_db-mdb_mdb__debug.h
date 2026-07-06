--- ldap/servers/slapd/back-ldbm/db-mdb/mdb_debug.h.orig	2026-06-28 10:10:14 UTC
+++ ldap/servers/slapd/back-ldbm/db-mdb/mdb_debug.h
@@ -53,7 +53,7 @@ void dbi_str(MDB_cursor *cursor, int dbi, char dbistr[
 #define TXN_ABORT(txn) dbg_txn_end(__FILE__,__LINE__,__FUNCTION__, txn, 0)
 #define TXN_RESET(txn) dbg_txn_reset(__FILE__,__LINE__,__FUNCTION__, txn)
 #define TXN_RENEW(txn) dbg_txn_renew(__FILE__,__LINE__,__FUNCTION__, txn)
-#define TXN_LOG(msg,txn) dbg_log(__FILE__,__LINE__,__FUNCTION__,DBGMDB_LEVEL_TXN, msg, (ulong)(txn))
+#define TXN_LOG(msg,txn) dbg_log(__FILE__,__LINE__,__FUNCTION__,DBGMDB_LEVEL_TXN, msg, (unsigned long)(txn))
 #define pthread_gettid() syscall(__NR_gettid)
 
 #define DBG_LOG(...) dbg_log(__FILE__,__LINE__,__FUNCTION__, __VA_ARGS__)
