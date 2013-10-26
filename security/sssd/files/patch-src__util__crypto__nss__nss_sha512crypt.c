From f5fbf2eee46f33a4614f0553403c8590ca04bb59 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 4 May 2013 16:08:12 +0200
Subject: [PATCH 23/34] patch-src__util__crypto__nss__nss_sha512crypt.c

---
 src/util/crypto/nss/nss_sha512crypt.c | 8 +++++---
 1 file changed, 5 insertions(+), 3 deletions(-)

diff --git src/util/crypto/nss/nss_sha512crypt.c src/util/crypto/nss/nss_sha512crypt.c
index 76eb8a6..db7582d 100644
--- src/util/crypto/nss/nss_sha512crypt.c
+++ src/util/crypto/nss/nss_sha512crypt.c
@@ -10,7 +10,7 @@
 
 #include "config.h"
 
-#include <endian.h>
+#include <sys/endian.h>
 #include <errno.h>
 #include <limits.h>
 #include <stdbool.h>
@@ -42,6 +42,8 @@ const char sha512_rounds_prefix[] = "rounds=";
 #define ROUNDS_MIN 1000
 #define ROUNDS_MAX 999999999
 
+#define __stpncpy(x, y, z) stpncpy(x, y, z)
+
 /* Table with characters for base64 transformation.  */
 const char b64t[64] =
     "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
@@ -205,7 +207,7 @@ static int sha512_crypt_r(const char *key,
     /* Create byte sequence P. */
     cp = p_bytes = alloca(key_len);
     for (cnt = key_len; cnt >= 64; cnt -= 64) {
-        cp = mempcpy(cp, temp_result, 64);
+	cp = (char *) memcpy(cp, temp_result, 64) + 64;
     }
     memcpy(cp, temp_result, cnt);
 
@@ -223,7 +225,7 @@ static int sha512_crypt_r(const char *key,
     /* Create byte sequence S.  */
     cp = s_bytes = alloca(salt_len);
     for (cnt = salt_len; cnt >= 64; cnt -= 64) {
-        cp = mempcpy(cp, temp_result, 64);
+	cp = (char *) memcpy(cp, temp_result, 64) + 64;
     }
     memcpy(cp, temp_result, cnt);
 
-- 
1.8.0

