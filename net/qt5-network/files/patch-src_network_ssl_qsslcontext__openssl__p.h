--- src/network/ssl/qsslcontext_openssl_p.h.orig	2022-06-22 10:58:13 UTC
+++ src/network/ssl/qsslcontext_openssl_p.h
@@ -61,6 +61,13 @@
 
 QT_BEGIN_NAMESPACE
 
+#ifndef DTLS_ANY_VERSION
+#define DTLS_ANY_VERSION 0x1FFFF
+#endif
+#ifndef TLS_ANY_VERSION
+#define TLS_ANY_VERSION 0x10000
+#endif
+
 #ifndef QT_NO_SSL
 
 class QSslContextPrivate;
