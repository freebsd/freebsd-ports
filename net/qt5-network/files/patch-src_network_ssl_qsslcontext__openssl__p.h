Patch from Gentoo: https://gitweb.gentoo.org/repo/gentoo.git/plain/dev-qt/qtnetwork/files/qtnetwork-5.15.1-libressl.patch
--- src/network/ssl/qsslcontext_openssl_p.h.orig	2020-09-02 10:15:07 UTC
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
