--- libfreerdp/crypto/tls.c.orig	2017-07-24 08:46:54 UTC
+++ libfreerdp/crypto/tls.c
@@ -853,13 +853,13 @@ int tls_connect(rdpTls* tls, BIO* underlying)
 	if (!tls_prepare(tls, underlying, SSLv23_client_method(), options, TRUE))
 		return FALSE;
 
-#ifndef OPENSSL_NO_TLSEXT
+#if !defined(OPENSSL_NO_TLSEXT) && !defined(LIBRESSL_VERSION_NUMBER)
 	SSL_set_tlsext_host_name(tls->ssl, tls->hostname);
 #endif
 	return tls_do_handshake(tls, TRUE);
 }
 
-#if defined(MICROSOFT_IOS_SNI_BUG) && !defined(OPENSSL_NO_TLSEXT)
+#if defined(MICROSOFT_IOS_SNI_BUG) && !defined(OPENSSL_NO_TLSEXT) && !defined(LIBRESSL_VERSION_NUMBER)
 static void tls_openssl_tlsext_debug_callback(SSL* s, int client_server,
         int type, unsigned char* data, int len, void* arg)
 {
@@ -1002,7 +1002,7 @@ BOOL tls_accept(rdpTls* tls, BIO* underlying, rdpSetti
 		return FALSE;
 	}
 
-#if defined(MICROSOFT_IOS_SNI_BUG) && !defined(OPENSSL_NO_TLSEXT)
+#if defined(MICROSOFT_IOS_SNI_BUG) && !defined(OPENSSL_NO_TLSEXT) && !defined(LIBRESSL_VERSION_NUMBER)
 	SSL_set_tlsext_debug_callback(tls->ssl, tls_openssl_tlsext_debug_callback);
 #endif
 	return tls_do_handshake(tls, FALSE) > 0;
