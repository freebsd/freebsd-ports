--- src/gssl/gssl_openssl.cpp.orig	2013-12-07 22:55:47 UTC
+++ src/gssl/gssl_openssl.cpp
@@ -292,8 +292,10 @@ GSsl::Context::Context( const std::strin
 {
 	if( (flags&3U) == 2U )
 		m_ssl_ctx = SSL_CTX_new(SSLv23_method()) ;
+#ifndef OPENSSL_NO_SSL3
 	else if( (flags&3U) == 3U )
 		m_ssl_ctx = SSL_CTX_new(SSLv3_method()) ;
+#endif
 	else
 		m_ssl_ctx = SSL_CTX_new(TLSv1_method()) ;
 
