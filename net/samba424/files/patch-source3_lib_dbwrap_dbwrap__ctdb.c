--- source3/lib/dbwrap/dbwrap_ctdb.c.orig	2026-01-20 15:42:54 UTC
+++ source3/lib/dbwrap/dbwrap_ctdb.c
@@ -38,6 +38,9 @@
 #include "lib/cluster_support.h"
 #include "lib/util/tevent_ntstatus.h"
 
+#undef DBGC_CLASS
+#define DBGC_CLASS DBGC_LOCKING
+
 struct db_ctdb_transaction_handle {
 	struct db_ctdb_ctx *ctx;
 	/*
