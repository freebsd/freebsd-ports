--- lib/dbwrap/dbwrap_util.c.orig	2026-01-20 15:42:54 UTC
+++ lib/dbwrap/dbwrap_util.c
@@ -26,6 +26,9 @@
 #include "dbwrap.h"
 #include "lib/util/util_tdb.h"
 
+#undef DBGC_CLASS
+#define DBGC_CLASS DBGC_LOCKING
+
 struct dbwrap_fetch_int32_state {
 	NTSTATUS status;
 	int32_t result;
