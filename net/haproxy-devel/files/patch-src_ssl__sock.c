--- src/ssl_sock.c.orig	2016-04-16 19:10:08 UTC
+++ src/ssl_sock.c
@@ -1697,7 +1697,7 @@ static int ssl_sock_add_cert_sni(SSL_CTX
 /* The following code is used for loading multiple crt files into
  * SSL_CTX's based on CN/SAN
  */
-#if OPENSSL_VERSION_NUMBER >= 0x1000200fL
+#if OPENSSL_VERSION_NUMBER >= 0x1000200fL && !defined(LIBRESSL_VERSION_NUMBER)
 /* This is used to preload the certifcate, private key
  * and Cert Chain of a file passed in via the crt
  * argument
