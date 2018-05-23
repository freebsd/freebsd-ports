--- src/crypto/scrypt.cpp.orig	2018-02-26 19:37:55.000000000 -0500
+++ src/crypto/scrypt.cpp	2018-05-23 11:25:45.718849000 -0400
@@ -32,6 +32,7 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <string.h>
+#include <sys/endian.h>
 #include <openssl/sha.h>
 
 #if defined(USE_SSE2) && !defined(USE_SSE2_ALWAYS)
@@ -42,24 +43,6 @@
 // GCC Linux or i686-w64-mingw32
 #include <cpuid.h>
 #endif
-#endif
-#ifndef __FreeBSD__
-static inline uint32_t be32dec(const void *pp)
-{
-	const uint8_t *p = (uint8_t const *)pp;
-	return ((uint32_t)(p[3]) + ((uint32_t)(p[2]) << 8) +
-	    ((uint32_t)(p[1]) << 16) + ((uint32_t)(p[0]) << 24));
-}
-
-static inline void be32enc(void *pp, uint32_t x)
-{
-	uint8_t *p = (uint8_t *)pp;
-	p[3] = x & 0xff;
-	p[2] = (x >> 8) & 0xff;
-	p[1] = (x >> 16) & 0xff;
-	p[0] = (x >> 24) & 0xff;
-}
-
 #endif
 typedef struct HMAC_SHA256Context {
 	SHA256_CTX ictx;
