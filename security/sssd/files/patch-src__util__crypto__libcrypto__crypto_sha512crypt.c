From 557ea27d9f1a8f86dc769ea6c174055992ebf803 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 4 May 2013 16:08:12 +0200
Subject: [PATCH 22/34] patch-src__util__crypto__libcrypto__crypto_sha512crypt.c

---
 src/util/crypto/libcrypto/crypto_sha512crypt.c | 10 +++++-----
 1 file changed, 5 insertions(+), 5 deletions(-)

diff --git src/util/crypto/libcrypto/crypto_sha512crypt.c src/util/crypto/libcrypto/crypto_sha512crypt.c
index f4c3e0d..ed77fa6 100644
--- src/util/crypto/libcrypto/crypto_sha512crypt.c
+++ src/util/crypto/libcrypto/crypto_sha512crypt.c
@@ -10,9 +10,7 @@
 /* SHA512-based Unix crypt implementation.
    Released into the Public Domain by Ulrich Drepper <drepper@redhat.com>.  */
 
-#include "config.h"
-
-#include <endian.h>
+#include <sys/endian.h>
 #include <errno.h>
 #include <limits.h>
 #include <stdbool.h>
@@ -41,6 +39,8 @@ const char sha512_rounds_prefix[] = "rounds=";
 #define ROUNDS_MIN 1000
 #define ROUNDS_MAX 999999999
 
+#define __stpncpy(x, y, z) stpncpy(x, y, z)
+
 /* Table with characters for base64 transformation.  */
 const char b64t[64] =
     "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
@@ -198,7 +198,7 @@ static int sha512_crypt_r(const char *key,
     /* Create byte sequence P. */
     cp = p_bytes = alloca(key_len);
     for (cnt = key_len; cnt >= 64; cnt -= 64) {
-        cp = mempcpy(cp, temp_result, 64);
+	cp = (char *) memcpy(cp, temp_result, 64) + 64;
     }
     memcpy(cp, temp_result, cnt);
 
@@ -219,7 +219,7 @@ static int sha512_crypt_r(const char *key,
     /* Create byte sequence S.  */
     cp = s_bytes = alloca(salt_len);
     for (cnt = salt_len; cnt >= 64; cnt -= 64) {
-        cp = mempcpy(cp, temp_result, 64);
+	cp = (char *) memcpy(cp, temp_result, 64) + 64;
     }
     memcpy(cp, temp_result, cnt);
 
-- 
1.8.0

