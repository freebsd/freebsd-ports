$OpenBSD: patch-src_tls_tls_h,v 1.2 2017/03/04 22:09:43 sthen Exp $

Fix building with LibreSSL

--- src/tls/tls.h.orig	2017-01-01 22:22:13 UTC
+++ src/tls/tls.h
@@ -89,7 +89,7 @@ extern const char *str_tls_level(int);
 #endif
 
  /* Backwards compatibility with OpenSSL < 1.1.0 */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #define OpenSSL_version_num SSLeay
 #define OpenSSL_version SSLeay_version
 #define OPENSSL_VERSION SSLEAY_VERSION
@@ -104,6 +104,9 @@ extern const char *str_tls_level(int);
 #define ASN1_STRING_get0_data ASN1_STRING_data
 #define X509_getm_notBefore X509_get_notBefore
 #define X509_getm_notAfter X509_get_notAfter
+#endif
+
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 #define TLS_method SSLv23_method
 #define TLS_client_method SSLv23_client_method
 #define TLS_server_method SSLv23_server_method
