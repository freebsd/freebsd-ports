--- src/acl/external/session/ext_session_acl.cc.orig	2020-04-19 10:50:48 UTC
+++ src/acl/external/session/ext_session_acl.cc
@@ -137,7 +137,7 @@ static void init_db(void)
         }
     }
 #elif USE_TRIVIALDB
-    db = tdb_open(db_path, 0, TDB_CLEAR_IF_FIRST, O_CREAT|O_DSYNC, 0666);
+    db = tdb_open(db_path, 0, TDB_CLEAR_IF_FIRST, O_CREAT|O_SYNC, 0666);
 #endif
     if (!db) {
         fprintf(stderr, "FATAL: %s: Failed to open session db '%s'\n", program_name, db_path);
