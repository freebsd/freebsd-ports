# fix build against LibreSSL
# Obtained from: http://cvsweb.openbsd.org/cgi-bin/cvsweb/ports/mail/postfix/stable/patches/
# 
--- src/tls/tls.h.orig	2016-02-06 20:09:41 UTC
+++ src/tls/tls.h
@@ -89,7 +89,7 @@ extern const char *str_tls_level(int);
 #endif
 
  /* Backwards compatibility with OpenSSL < 1.1.0 */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #define OpenSSL_version_num SSLeay
 #define OpenSSL_version SSLeay_version
 #define OPENSSL_VERSION SSLEAY_VERSION
