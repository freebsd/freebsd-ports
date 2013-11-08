From be27b76238aa49ac0ace123f80c9957ae25501fa Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Wed, 6 Nov 2013 22:01:21 +0100
Subject: [PATCH 20/25] patch-src__util__crypto__nss__nss_sha512crypt.c

---
 src/util/crypto/nss/nss_sha512crypt.c | 8 ++++++++
 1 file changed, 8 insertions(+)

diff --git src/util/crypto/nss/nss_sha512crypt.c src/util/crypto/nss/nss_sha512crypt.c
index 2838c47..a6cf43f 100644
--- src/util/crypto/nss/nss_sha512crypt.c
+++ src/util/crypto/nss/nss_sha512crypt.c
@@ -29,6 +29,14 @@
 #include <sechash.h>
 #include <pk11func.h>
 
+#define __stpncpy(x, y, z) stpncpy(x, y, z)
+
+static void *
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

