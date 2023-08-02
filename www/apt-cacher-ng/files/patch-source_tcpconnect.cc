--- source/tcpconnect.cc.orig	2020-02-03 18:54:57 UTC
+++ source/tcpconnect.cc
@@ -41,13 +41,13 @@ atomic_int nConCount(0), nDisconCount(0), nReuseCount(
 #include <openssl/crypto.h>
 #include <openssl/x509_vfy.h>
 #include <openssl/x509v3.h>
-#endif
 #ifndef HAVE_SSL_HOST_VALIDATION
 extern "C"
 {
 #include "oldssl-workaround/openssl_hostname_validation.h"
 }
 #endif
+#endif
 
 namespace acng
 {
@@ -626,7 +626,9 @@ void globalSslInit()
 		return;
 	inited = true;
 	SSL_load_error_strings();
+#if OPENSSL_VERSION_NUMBER < 0x30000000L
 	ERR_load_BIO_strings();
+#endif
 	ERR_load_crypto_strings();
 	ERR_load_SSL_strings();
 	OpenSSL_add_all_algorithms();
