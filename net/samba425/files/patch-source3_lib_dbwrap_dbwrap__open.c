--- source3/lib/dbwrap/dbwrap_open.c.orig	2026-01-20 15:42:54 UTC
+++ source3/lib/dbwrap/dbwrap_open.c
@@ -31,6 +31,9 @@
 #include "ctdbd_conn.h"
 #include "global_contexts.h"
 
+#undef DBGC_CLASS
+#define DBGC_CLASS DBGC_LOCKING
+
 bool db_is_local(const char *name)
 {
 	const char *sockname = lp_ctdbd_socket();
