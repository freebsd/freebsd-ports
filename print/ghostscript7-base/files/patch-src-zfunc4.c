--- src/zfunc4.c.orig	2013-04-30 10:45:00.000000000 +0900
+++ src/zfunc4.c	2013-04-30 10:45:23.000000000 +0900
@@ -150,10 +150,6 @@
 	case t_integer: {
 	    int i = elt.value.intval;
 
-#if ARCH_SIZEOF_INT < ARCH_SIZEOF_LONG
-	    if (i != elt.value.intval) /* check for truncation */
-		return_error(e_rangecheck);
-#endif
 	    if (i == (byte)i) {
 		*p = PtCr_byte;
 		p[1] = (byte)i;
