--- lib/krb5/krb/rd_rep.c.orig	Fri Jun 13 17:09:47 2003
+++ lib/krb5/krb/rd_rep.c	Wed Sep  1 11:46:52 2004
@@ -71,6 +71,8 @@
 
     /* now decode the decrypted stuff */
     retval = decode_krb5_ap_rep_enc_part(&scratch, repl);
+    if (retval)
+	goto clean_scratch;
 
     /* Check reply fields */
     if (((*repl)->ctime != auth_context->authentp->ctime) ||
