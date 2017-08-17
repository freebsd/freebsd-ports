--- tlscommon.c.orig	2016-09-21 11:49:09 UTC
+++ tlscommon.c
@@ -217,7 +217,7 @@ static SSL_CTX *tlscreatectx(uint8_t typ
 #endif
 #ifdef RADPROT_DTLS
     case RAD_DTLS:
-#if OPENSSL_VERSION_NUMBER >= 0x10002000
+#if OPENSSL_VERSION_NUMBER >= 0x10002000 && !defined(LIBRESSL_VERSION_NUMBER)
         /* DTLS_method() seems to have been introduced in OpenSSL 1.0.2. */
 	ctx = SSL_CTX_new(DTLS_method());
 #else
