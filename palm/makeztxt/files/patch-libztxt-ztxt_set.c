--- libztxt/ztxt_set.c.orig	Mon May 28 20:12:33 2007
+++ libztxt/ztxt_set.c	Mon May 28 20:12:44 2007
@@ -40,7 +40,7 @@
 void
 ztxt_set_title(ztxt *db, char *new_title)
 {
-  strncpy(db->dbHeader->name, new_title, dmDBNameLength);
+  strncpy((char *)db->dbHeader->name, new_title, dmDBNameLength);
   db->dbHeader->name[dmDBNameLength - 1] = '\0';
 }
 
