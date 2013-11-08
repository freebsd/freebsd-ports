From 74422233fe8c6efa826b20c6b579f4c99e45ff87 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Wed, 6 Nov 2013 22:01:21 +0100
Subject: [PATCH 19/25] patch-src__util__crypto__libcrypto__crypto_sha512crypt.c

---
 src/util/crypto/libcrypto/crypto_sha512crypt.c | 8 ++++++++
 1 file changed, 8 insertions(+)

diff --git src/util/crypto/libcrypto/crypto_sha512crypt.c src/util/crypto/libcrypto/crypto_sha512crypt.c
index 88628b6..4510403 100644
--- src/util/crypto/libcrypto/crypto_sha512crypt.c
+++ src/util/crypto/libcrypto/crypto_sha512crypt.c
@@ -28,6 +28,14 @@
 #include <openssl/evp.h>
 #include <openssl/rand.h>
 
+#define __stpncpy(x, y, z) stpncpy(x, y, z)
+
+void *
+mempcpy (void *dest, const void *src, size_t n)
+{
+  return (char *) memcpy (dest, src, n) + n;
+}
+
 /* Define our magic string to mark salt for SHA512 "encryption" replacement. */
 const char sha512_salt_prefix[] = "$6$";
 #define SALT_PREF_SIZE (sizeof(sha512_salt_prefix) - 1)
-- 
1.8.0

