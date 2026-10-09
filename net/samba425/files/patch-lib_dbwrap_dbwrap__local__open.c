--- lib/dbwrap/dbwrap_local_open.c.orig	2026-01-20 15:42:54 UTC
+++ lib/dbwrap/dbwrap_local_open.c
@@ -23,6 +23,9 @@
 #include "dbwrap/dbwrap_tdb.h"
 #include "tdb.h"
 
+#undef DBGC_CLASS
+#define DBGC_CLASS DBGC_LOCKING
+
 struct db_context *dbwrap_local_open(TALLOC_CTX *mem_ctx,
 				     const char *name,
 				     int hash_size, int tdb_flags,
