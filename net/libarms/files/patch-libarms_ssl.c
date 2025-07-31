--- libarms/ssl.c.orig	2019-03-29 01:15:24 UTC
+++ libarms/ssl.c
@@ -338,7 +338,8 @@ arms_ssl_dhparam(SSL_CTX *ctx)
 	}
 
 /* for compatibility with before OpenSSL-1.1.0 and LibreSSL-2.7.0 */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || LIBRESSL_VERSION_NUMBER < 0x20700000L
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || \
+	(defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
 	dh->p = p;
 	dh->g = g;
 #else
