--- src/zstack.c.orig	2003-01-17 00:49:06 UTC
+++ src/zstack.c
@@ -70,7 +70,7 @@ zindex(i_ctx_t *i_ctx_p)
     register os_ptr opn;
 
     check_type(*op, t_integer);
-    if ((ulong)op->value.intval >= op - osbot) {
+    if ((uint)op->value.intval >= op - osbot) {
 	/* Might be in an older stack block. */
 	ref *elt;
 
