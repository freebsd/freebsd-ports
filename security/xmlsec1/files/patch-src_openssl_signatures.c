--- src/openssl/signatures.c.orig	2016-04-20 16:26:22 UTC
+++ src/openssl/signatures.c
@@ -10,6 +10,7 @@
 
 #include <string.h>
 
+#include <openssl/ecdsa.h> // ECDSA_SIG
 #include <openssl/evp.h>
 #include <openssl/rand.h>
 #include <openssl/sha.h>
