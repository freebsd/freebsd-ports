--- programs/IRRd/database.c.orig	Fri Oct 18 05:02:29 2002
+++ programs/IRRd/database.c	Thu Apr 22 17:13:52 2004
@@ -61,7 +61,9 @@
     HASH_Clear (db->hash_spec);
 
   db->radix = New_Radix (128);
-  fclose (db->db_fp);
+
+  if (db->db_fp != NULL)
+    fclose (db->db_fp);
 
   db->db_fp = NULL;
   db->db_syntax = EMPTY_DB;
