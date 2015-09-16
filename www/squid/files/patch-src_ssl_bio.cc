--- src/ssl/bio.cc.orig	2015-09-01 21:52:00.000000000 +0200
+++ src/ssl/bio.cc	2015-09-10 14:56:46.695514356 +0200
@@ -1000,7 +1000,7 @@ Ssl::Bio::sslFeatures::parseV3Hello(cons
 
         ciphers += 2;
         if (ciphersLen) {
-            const SSL_METHOD *method = SSLv3_method();
+            const SSL_METHOD *method = SSLv23_method();
             const int cs = method->put_cipher_by_char(NULL, NULL);
             assert(cs > 0);
             for (size_t i = 0; i < ciphersLen; i += cs) {
