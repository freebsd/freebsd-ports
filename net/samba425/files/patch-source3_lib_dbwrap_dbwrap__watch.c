--- source3/lib/dbwrap/dbwrap_watch.c.orig	2026-01-20 15:42:54 UTC
+++ source3/lib/dbwrap/dbwrap_watch.c
@@ -29,6 +29,9 @@
 #include "server_id_watch.h"
 #include "lib/dbwrap/dbwrap_private.h"
 
+#undef DBGC_CLASS
+#define DBGC_CLASS DBGC_LOCKING
+
 struct dbwrap_watcher {
 	/*
 	 * Process watching this record
