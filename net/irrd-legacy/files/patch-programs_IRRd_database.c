--- programs/IRRd/database.c.orig	2015-04-03 11:26:26 UTC
+++ programs/IRRd/database.c
@@ -59,9 +59,11 @@ void database_clear (irr_database_t *db) {
 
   db->radix_v4 = New_Radix (32);
   db->radix_v6 = New_Radix (128);
-  fclose (db->db_fp);
 
-  db->db_fp = NULL;
+  if (db->db_fp) {
+    fclose (db->db_fp);
+    db->db_fp = NULL;
+  }
 }
 
 
