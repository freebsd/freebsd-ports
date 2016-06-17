--- src/zfunc4.c.orig	2003-01-17 00:49:06 UTC
+++ src/zfunc4.c
@@ -150,10 +150,6 @@ check_psc_function(i_ctx_t *i_ctx_p, con
 	case t_integer: {
 	    int i = elt.value.intval;
 
-#if ARCH_SIZEOF_INT < ARCH_SIZEOF_LONG
-	    if (i != elt.value.intval) /* check for truncation */
-		return_error(e_rangecheck);
-#endif
 	    if (i == (byte)i) {
 		*p = PtCr_byte;
 		p[1] = (byte)i;
