--- libbalsa/mailbox_imap.c.orig	Tue Aug 10 02:38:45 2004
+++ libbalsa/mailbox_imap.c	Tue Aug 10 02:38:53 2004
@@ -2230,8 +2230,8 @@
 {
     unsigned *msgno_arr, *msgno_map, len, i, no_max;
     GArray *tmp;
-    len = array->len;
     ImapResponse rc;
+    len = array->len;
 
     if(mbox->view->sort_field == LB_MAILBOX_SORT_NO) {
         g_array_sort_with_data(array, (GCompareDataFunc)lbmi_compare_func,
