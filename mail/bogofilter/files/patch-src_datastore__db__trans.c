--- a/src/datastore_db_trans.c	8 Jun 2005 12:18:59 -0000	1.31.4.1
+++ b/src/datastore_db_trans.c	9 Jun 2005 07:54:35 -0000	1.31.4.2
@@ -943,8 +943,10 @@
 #else
     r = ENOENT;
 #endif
-    if (r == DB_RUNRECOVERY)
+    if (r == DB_RUNRECOVERY) {
+	dbe->close(dbe, 0);
 	return T_ENABLED;
+    }
 
     if (r == ENOENT) {
 	struct stat st;
