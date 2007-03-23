
$FreeBSD$

--- src/tls-openssl.c.orig
+++ src/tls-openssl.c
@@ -343,8 +343,7 @@
 /* Set up the information callback, which outputs if debugging is at a suitable
 level. */
 
-if (!(SSL_CTX_set_info_callback(ctx, (void (*)())info_callback)))
-  return tls_error(US"SSL_CTX_set_info_callback", host);
+SSL_CTX_set_info_callback(ctx, (void (*)())info_callback);
 
 /* The following patch was supplied by Robert Roselius */
 
