--- lib/Pz/crypto/hmac/hmac.c	2002-05-27 18:56:19.000000000 +0900
+++ lib/Pz/crypto/hmac/hmac.c	2008-01-01 04:48:38.000000000 +0900
@@ -60,7 +60,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <openssl/hmac.h>
+#include "hmac.h"
 
 void HMAC_Init(HMAC_CTX *ctx, const void *key, int len,
 	       const EVP_MD *md)
