--- src/zgeneric.c.orig	2013-04-30 10:55:48.000000000 +0900
+++ src/zgeneric.c	2013-04-30 10:56:40.000000000 +0900
@@ -76,7 +76,7 @@
     int count, i;
     int code;
 
-    if ((ulong) op->value.intval > op - osbot) {
+    if ((uint)op->value.intval > (uint)(op - osbot)) {
 	/* There might be enough elements in other blocks. */
 	check_int_ltu(*op, ref_stack_count(&o_stack));
 	count = op->value.intval;
@@ -471,7 +471,7 @@
 {
     os_ptr op = osp;
     es_ptr obj = esp - 2;
-    int index = (int)esp->value.intval;
+    int index = esp->value.intval;
 
     push(2);			/* make room for key and value */
     if ((index = dict_next(obj, index, op - 1)) >= 0) {	/* continue */
