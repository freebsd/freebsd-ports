--- src/crypto.h.orig	2014-07-12 04:24:03.000000000 +0200
+++ src/crypto.h	2014-11-02 21:23:28.529312627 +0100
@@ -34,6 +34,7 @@
 
 #ifndef _CRYPTO_H
 #define _CRYPTO_H
+#include <sys/types.h>
 
 #ifdef USE_GCRYPT
 #include "gcrypt-openssl-wrapper.h"
