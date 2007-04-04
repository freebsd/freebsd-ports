--- lib/gssapi/krb5/k5unseal.c.orig	Tue May  9 04:31:02 2006
+++ lib/gssapi/krb5/k5unseal.c	Tue Apr  3 18:28:48 2007
@@ -457,8 +457,11 @@
 
     if ((ctx->initiate && direction != 0xff) ||
 	(!ctx->initiate && direction != 0)) {
-	if (toktype == KG_TOK_SEAL_MSG)
+	if (toktype == KG_TOK_SEAL_MSG) {
 	    xfree(token.value);
+	    message_buffer->value = NULL;
+	    message_buffer->length = 0;
+	}
 	*minor_status = G_BAD_DIRECTION;
 	return(GSS_S_BAD_SIG);
     }
