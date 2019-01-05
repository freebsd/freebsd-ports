--- source/tcpconnect.cc.orig	2018-09-07 13:02:18 UTC
+++ source/tcpconnect.cc
@@ -41,13 +41,13 @@ atomic_int nConCount(0), nDisconCount(0)
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
