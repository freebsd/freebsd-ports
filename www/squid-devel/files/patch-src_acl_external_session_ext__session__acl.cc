--- src/acl/external/session/ext_session_acl.cc.orig	2020-05-10 08:32:32 UTC
+++ src/acl/external/session/ext_session_acl.cc
@@ -137,6 +137,10 @@ static void init_db(void)
         }
     }
 #elif USE_TRIVIALDB
+#if _SQUID_FREEBSD_ && !defined(O_DSYNC)
+    // FreeBSD lacks O_DSYNC, O_SYNC is closest to correct behaviour
+#define O_DSYNC O_SYNC
+#endif
     db = tdb_open(db_path, 0, TDB_CLEAR_IF_FIRST, O_CREAT|O_DSYNC, 0666);
 #endif
     if (!db) {
