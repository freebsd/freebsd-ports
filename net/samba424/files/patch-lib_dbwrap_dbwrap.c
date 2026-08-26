--- lib/dbwrap/dbwrap.c.orig	2026-01-20 15:42:54 UTC
+++ lib/dbwrap/dbwrap.c
@@ -28,6 +28,9 @@
 #include "lib/util/util_tdb.h"
 #include "lib/util/tevent_ntstatus.h"
 
+#undef DBGC_CLASS
+#define DBGC_CLASS DBGC_LOCKING
+
 /*
  * Fall back using fetch if no genuine exists operation is provided
  */
