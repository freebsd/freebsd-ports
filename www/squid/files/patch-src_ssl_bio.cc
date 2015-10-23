--- src/ssl/bio.cc.orig	2015-10-01 14:52:11 UTC
+++ src/ssl/bio.cc
@@ -1009,7 +1009,7 @@ Ssl::Bio::sslFeatures::parseV3Hello(cons
 
     ciphers += 2;
     if (ciphersLen) {
-        const SSL_METHOD *method = SSLv3_method();
+        const SSL_METHOD *method = SSLv23_method();
         for (size_t i = 0; i < ciphersLen; i += 2) {
             // each cipher in v3/tls  HELLO message is of size 2
             const SSL_CIPHER *c = method->get_cipher_by_char((ciphers + i));
