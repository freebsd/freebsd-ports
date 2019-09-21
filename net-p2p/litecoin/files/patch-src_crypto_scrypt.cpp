--- src/crypto/scrypt.cpp.orig	2019-09-19 19:04:21 UTC
+++ src/crypto/scrypt.cpp
@@ -60,6 +60,8 @@ static inline void be32enc(void *pp, uint32_t x)
 	p[0] = (x >> 24) & 0xff;
 }
 
+#else
+#include <sys/endian.h>
 #endif
 typedef struct HMAC_SHA256Context {
 	SHA256_CTX ictx;
