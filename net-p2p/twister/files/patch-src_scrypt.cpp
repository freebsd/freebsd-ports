--- src/scrypt.cpp.orig	2014-06-03 22:36:01.000000000 +0200
+++ src/scrypt.cpp	2014-06-15 23:01:59.000000000 +0200
@@ -34,6 +34,8 @@
 #include <string.h>
 #include <openssl/sha.h>
 
+#ifndef __FreeBSD__
+/* Allready defined in sys/endian.h */
 static inline uint32_t be32dec(const void *pp)
 {
 	const uint8_t *p = (uint8_t const *)pp;
@@ -49,6 +51,7 @@
 	p[1] = (x >> 16) & 0xff;
 	p[0] = (x >> 24) & 0xff;
 }
+#endif
 
 typedef struct HMAC_SHA256Context {
 	SHA256_CTX ictx;
