--- src/ziodev.c.orig	2003-01-17 00:49:06 UTC
+++ src/ziodev.c
@@ -79,8 +79,6 @@ zgetiodevice(i_ctx_t *i_ctx_p)
     const byte *dname;
 
     check_type(*op, t_integer);
-    if (op->value.intval != (int)op->value.intval)
-	return_error(e_rangecheck);
     iodev = gs_getiodevice((int)(op->value.intval));
     if (iodev == 0)		/* index out of range */
 	return_error(e_rangecheck);
