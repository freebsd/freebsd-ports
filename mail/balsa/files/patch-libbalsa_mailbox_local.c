--- libbalsa/mailbox_local.c.orig	2009-05-23 03:02:12.000000000 -0400
+++ libbalsa/mailbox_local.c	2009-12-25 12:39:52.000000000 -0500
@@ -440,7 +440,7 @@ libbalsa_mailbox_local_load_config(LibBa
 
 typedef struct {
     GArray * array;
-    guint (*fileno)(LibBalsaMailboxLocal * local, guint msgno);
+    guint (*sti_fileno)(LibBalsaMailboxLocal * local, guint msgno);
     LibBalsaMailboxLocal *local;
 } LibBalsaMailboxLocalSaveTreeInfo;
 
@@ -464,9 +464,9 @@ lbm_local_save_tree_item(guint msgno, gu
     if (msgno == 0) {
         info.msgno = msgno;
         info.value.total = a;
-    } else if (save_info->fileno) {
-        info.msgno = save_info->fileno(save_info->local, msgno);
-        info.value.parent = save_info->fileno(save_info->local, a);
+    } else if (save_info->sti_fileno) {
+        info.msgno = save_info->sti_fileno(save_info->local, msgno);
+        info.value.parent = save_info->sti_fileno(save_info->local, a);
     } else {
         info.msgno = msgno;
         info.value.parent = a;
@@ -524,7 +524,7 @@ lbm_local_save_tree(LibBalsaMailboxLocal
         return;
     }
 
-    save_info.fileno = LIBBALSA_MAILBOX_LOCAL_GET_CLASS(local)->fileno;
+    save_info.sti_fileno = LIBBALSA_MAILBOX_LOCAL_GET_CLASS(local)->sti_fileno;
     save_info.local = local;
     save_info.array =
         g_array_new(FALSE, FALSE, sizeof(LibBalsaMailboxLocalTreeInfo));
