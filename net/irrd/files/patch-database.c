--- programs/IRRd/database.c~	2009-03-25 00:21:26.000000000 +0300
+++ programs/IRRd/database.c	2012-03-15 10:53:03.000000000 +0400
@@ -59,9 +59,11 @@
 
   db->radix_v4 = New_Radix (32);
   db->radix_v6 = New_Radix (128);
-  fclose (db->db_fp);
 
-  db->db_fp = NULL;
+  if (db->db_fp) {
+    fclose (db->db_fp);
+    db->db_fp = NULL;
+  }
 }
 
 
