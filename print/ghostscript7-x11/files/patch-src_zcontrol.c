--- src/zcontrol.c.orig	2003-01-17 00:49:05 UTC
+++ src/zcontrol.c
@@ -356,7 +356,7 @@ for_pos_int_continue(i_ctx_t *i_ctx_p)
 {
     os_ptr op = osp;
     register es_ptr ep = esp;
-    long var = ep[-3].value.intval;
+    int var = ep[-3].value.intval;
 
     if (var > ep[-1].value.intval) {
 	esp -= 5;		/* pop everything */
@@ -375,7 +375,7 @@ for_neg_int_continue(i_ctx_t *i_ctx_p)
 {
     os_ptr op = osp;
     register es_ptr ep = esp;
-    long var = ep[-3].value.intval;
+    int var = ep[-3].value.intval;
 
     if (var < ep[-1].value.intval) {
 	esp -= 5;		/* pop everything */
