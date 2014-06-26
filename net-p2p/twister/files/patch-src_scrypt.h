--- src/scrypt.h.orig	2014-06-03 22:36:01.000000000 +0200
+++ src/scrypt.h	2014-06-15 22:44:40.000000000 +0200
@@ -17,6 +17,8 @@
 PBKDF2_SHA256(const uint8_t *passwd, size_t passwdlen, const uint8_t *salt,
     size_t saltlen, uint64_t c, uint8_t *buf, size_t dkLen);
 
+# ifndef __FreeBSD__
+/* Allready defined in sys/endian.h */
 static inline uint32_t le32dec(const void *pp)
 {
         const uint8_t *p = (uint8_t const *)pp;
@@ -32,4 +34,5 @@
         p[2] = (x >> 16) & 0xff;
         p[3] = (x >> 24) & 0xff;
 }
+# endif
 #endif
