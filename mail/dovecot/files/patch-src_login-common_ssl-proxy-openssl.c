--- src/login-common/ssl-proxy-openssl.c.orig	2011-01-20 22:16:59.000000000 +0100
+++ src/login-common/ssl-proxy-openssl.c	2015-02-22 15:13:39.245929556 +0100
@@ -635,7 +635,7 @@
 const char *ssl_proxy_get_security_string(struct ssl_proxy *proxy)
 {
 	SSL_CIPHER *cipher;
-#ifdef HAVE_SSL_COMPRESSION
+#if defined(HAVE_SSL_COMPRESSION) && !defined(OPENSSL_NO_COMP)
 	const COMP_METHOD *comp;
 #endif
 	int bits, alg_bits;
@@ -646,7 +646,7 @@
 
 	cipher = SSL_get_current_cipher(proxy->ssl);
 	bits = SSL_CIPHER_get_bits(cipher, &alg_bits);
-#ifdef HAVE_SSL_COMPRESSION
+#if defined(HAVE_SSL_COMPRESSION) && !defined(OPENSSL_NO_COMP)
 	comp = SSL_get_current_compression(proxy->ssl);
 	comp_str = comp == NULL ? "" :
 		t_strconcat(" ", SSL_COMP_get_name(comp), NULL);
