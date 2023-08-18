--- daemon/connect/TlsSocket.cpp.orig	2023-08-18 02:50:58 UTC
+++ daemon/connect/TlsSocket.cpp
@@ -188,7 +188,7 @@ void TlsSocket::Final()
 #endif /* HAVE_LIBGNUTLS */
 
 #ifdef HAVE_OPENSSL
-#ifndef LIBRESSL_VERSION_NUMBER
+#if	OPENSSL_VERSION_NUMBER < 0x30000000L && ! defined (LIBRESSL_VERSION_NUMBER)
 	FIPS_mode_set(0);
 #endif
 #ifdef NEED_CRYPTO_LOCKING
