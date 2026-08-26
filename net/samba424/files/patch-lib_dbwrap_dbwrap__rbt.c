--- lib/dbwrap/dbwrap_rbt.c.orig	2026-01-20 15:42:54 UTC
+++ lib/dbwrap/dbwrap_rbt.c
@@ -24,6 +24,9 @@
 #include "../lib/util/rbtree.h"
 #include "../lib/util/dlinklist.h"
 
+#undef DBGC_CLASS
+#define DBGC_CLASS DBGC_LOCKING
+
 #define DBWRAP_RBT_ALIGN(_size_) (((_size_)+15)&~15)
 
 struct db_rbt_ctx {
