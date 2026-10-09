--- lib/dbwrap/dbwrap_tdb.c.orig	2026-01-20 15:42:54 UTC
+++ lib/dbwrap/dbwrap_tdb.c
@@ -29,6 +29,9 @@
 #include "lib/param/param.h"
 #include "libcli/util/error.h"
 
+#undef DBGC_CLASS
+#define DBGC_CLASS DBGC_LOCKING
+
 struct db_tdb_ctx {
 	struct tdb_wrap *wtdb;
 
