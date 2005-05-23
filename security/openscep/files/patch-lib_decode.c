--- lib/decode.c.orig	Tue Feb 26 02:01:06 2002
+++ lib/decode.c	Thu May 19 16:23:01 2005
@@ -58,6 +58,7 @@
 			__LINE__, (scep->client) ? "reply" : "request");
 
 	/* convert from base64 to internal representation		*/
+	BIO_set_mem_eof_return(bio, 0);
 	if (msg->base64) {
 		if (debug)
 			BIO_printf(bio_err, "%s:%d: prepending Base64 "
