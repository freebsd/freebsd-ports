--- src/crypto.h.orig	2014-07-12 02:24:03 UTC
+++ src/crypto.h
@@ -34,6 +34,7 @@
 
 #ifndef _CRYPTO_H
 #define _CRYPTO_H
+#include <sys/types.h>
 
 #ifdef USE_GCRYPT
 #include "gcrypt-openssl-wrapper.h"
