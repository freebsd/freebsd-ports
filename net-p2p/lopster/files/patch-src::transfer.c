--- src/transfer.c.orig	Tue Mar  4 21:08:57 2003
+++ src/transfer.c	Wed Mar  5 23:23:53 2003
@@ -5907,6 +5907,7 @@
   GtkCList *clist;
   socket_t *socket;
   upload_t *upload;
+  share_t *share;
   int i1;
 
   if (!userinfo) return;
@@ -5915,10 +5916,15 @@
   gtk_clist_freeze(clist);
   for (i1 = 0; i1 < clist->rows; i1++) {
     socket = gtk_clist_get_row_data(clist, i1);
-    upload = socket->data;
-    if (upload->data->user_info != userinfo) continue;
-
-    upload_update(socket);
+    if (socket->type == S_UPLOAD) {
+      upload = socket->data;
+      if (upload->data->user_info != userinfo) continue;
+      upload_update(socket);
+    } else if (socket->type == S_SHARE) {
+      share = socket->data;
+      if (share->data->user_info != userinfo) continue;
+      share_update(socket);
+    }
   }
   gtk_clist_thaw(clist);
 }
