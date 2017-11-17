--- src/lib/prov/openssl/openssl_rsa.cpp.orig	2017-11-11 07:42:40 UTC
+++ src/lib/prov/openssl/openssl_rsa.cpp
@@ -17,6 +17,7 @@
 
 #include <functional>
 #include <memory>
+#include <cstdlib>
 
 #include <openssl/rsa.h>
 #include <openssl/x509.h>
