--- src/zstack.c.orig	2013-04-30 10:54:14.000000000 +0900
+++ src/zstack.c	2013-04-30 10:54:26.000000000 +0900
@@ -70,7 +70,7 @@
     register os_ptr opn;
 
     check_type(*op, t_integer);
-    if ((ulong)op->value.intval >= op - osbot) {
+    if ((uint)op->value.intval >= op - osbot) {
 	/* Might be in an older stack block. */
 	ref *elt;
 
