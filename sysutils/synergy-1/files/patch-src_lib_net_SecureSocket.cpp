--- src/lib/net/SecureSocket.cpp.orig	2018-03-01 20:07:30 UTC
+++ src/lib/net/SecureSocket.cpp
@@ -807,7 +807,7 @@ SecureSocket::showSecureCipherInfo()
         showCipherStackDesc(sStack);
     }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 	// m_ssl->m_ssl->session->ciphers is not forward compatable,
 	// In future release of OpenSSL, it's not visible,
     STACK_OF(SSL_CIPHER) * cStack = m_ssl->m_ssl->session->ciphers;
