===================================================================
RCS file: /cvsroot/meanwhile/meanwhile/src/srvc_aware.c,v
retrieving revision 1.10
retrieving revision 1.11
diff -u -r1.10 -r1.11
--- src/srvc_aware.c	2004/06/23 08:06:34	1.10
+++ src/srvc_aware.c	2004/06/28 18:20:29	1.11
@@ -514,6 +514,11 @@
   g_message("adding %i buddies", count);
 
   for(; count--; id_list++) {
+    if(id_list->user == NULL || *id_list->user == '\0') {
+      g_info("buddy's user id is empty, skipping");
+      continue;
+    }
+
     aware = g_hash_table_lookup(list->entries, id_list);
     if(aware) {
       g_info("buddy: %s, %s already exists",
