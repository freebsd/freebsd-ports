--- libbalsa/mailbox_local.c.orig	Thu Dec 29 01:47:25 2005
+++ libbalsa/mailbox_local.c	Thu Dec 29 01:48:23 2005
@@ -375,7 +375,7 @@ typedef struct {
 #else                           /* GLIB_CHECK_VERSION(2, 8, 0) */
     int fd;
 #endif                          /* GLIB_CHECK_VERSION(2, 8, 0) */
-    guint (*fileno)(LibBalsaMailboxLocal * local, guint msgno);
+    guint (*sti_fileno)(LibBalsaMailboxLocal * local, guint msgno);
     LibBalsaMailboxLocal *local;
 } LibBalsaMailboxLocalSaveTreeInfo;
 
@@ -399,9 +399,9 @@ lbm_local_save_tree_item(guint msgno, gu
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
@@ -466,7 +466,7 @@ lbm_local_save_tree(LibBalsaMailboxLocal
         return;
     }
 
-    save_info.fileno = LIBBALSA_MAILBOX_LOCAL_GET_CLASS(local)->fileno;
+    save_info.sti_fileno = LIBBALSA_MAILBOX_LOCAL_GET_CLASS(local)->sti_fileno;
     save_info.local = local;
 #if GLIB_CHECK_VERSION(2, 8, 0)
     save_info.array =
