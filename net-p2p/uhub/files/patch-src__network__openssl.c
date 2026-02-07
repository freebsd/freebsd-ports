--- src/network/openssl.c.orig	2014-08-06 18:56:07 UTC
+++ src/network/openssl.c
@@ -106,10 +106,12 @@ static const SSL_METHOD* get_ssl_method(
 
 	if (!strcmp(tls_version, "1.0"))
 	  return TLSv1_method();
+#if OPENSSL_VERSION_NUMBER >= 0x1000100fL
 	if (!strcmp(tls_version, "1.1"))
 	  return TLSv1_1_method();
 	if (!strcmp(tls_version, "1.2"))
 	  return TLSv1_2_method();
+#endif
 
 	LOG_ERROR("Unable to recognize tls_version.");
 	return 0;
