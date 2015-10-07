--- src/ziodev.c.orig	2013-04-30 11:06:19.000000000 +0900
+++ src/ziodev.c	2013-04-30 11:06:30.000000000 +0900
@@ -79,8 +79,6 @@
     const byte *dname;
 
     check_type(*op, t_integer);
-    if (op->value.intval != (int)op->value.intval)
-	return_error(e_rangecheck);
     iodev = gs_getiodevice((int)(op->value.intval));
     if (iodev == 0)		/* index out of range */
 	return_error(e_rangecheck);
