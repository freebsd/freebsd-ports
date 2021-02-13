- submitted by brnrd@ in PR#253486

From b22568a54506e4b79b72530f89f21032e6435414 Mon Sep 17 00:00:00 2001
From: Nick Mathewson <nickm@torproject.org>
Date: Fri, 6 Nov 2020 10:29:28 -0500
Subject: [PATCH] Rename OpenSSL_version_num() as defined in Tor

This way, if we guess wrong about whether the library has it,
we don't conflict with the library's headers.

Fixes #40181; bug not in any released version.
---
 src/lib/crypt_ops/compat_openssl.h     | 3 ++-
 src/lib/crypt_ops/crypto_openssl_mgt.c | 2 +-
 src/lib/tls/tortls_openssl.c           | 2 +-
 3 files changed, 4 insertions(+), 3 deletions(-)

diff --git a/src/lib/crypt_ops/compat_openssl.h b/src/lib/crypt_ops/compat_openssl.h
index c2e1459078..aa66e0c3fa 100644
--- src/lib/crypt_ops/compat_openssl.h.orig
+++ src/lib/crypt_ops/compat_openssl.h
@@ -34,7 +34,7 @@
 
 #ifndef OPENSSL_1_1_API
 #define OpenSSL_version(v) SSLeay_version(v)
-#define OpenSSL_version_num() SSLeay()
+#define tor_OpenSSL_version_num() SSLeay()
 #define RAND_OpenSSL() RAND_SSLeay()
 #define STATE_IS_SW_SERVER_HELLO(st)       \
   (((st) == SSL3_ST_SW_SRVR_HELLO_A) ||    \
@@ -42,6 +42,7 @@
 #define OSSL_HANDSHAKE_STATE int
 #define CONST_IF_OPENSSL_1_1_API
 #else /* defined(OPENSSL_1_1_API) */
+#define tor_OpenSSL_version_num() OpenSSL_version_num()
 #define STATE_IS_SW_SERVER_HELLO(st) \
   ((st) == TLS_ST_SW_SRVR_HELLO)
 #define CONST_IF_OPENSSL_1_1_API const
diff --git a/src/lib/crypt_ops/crypto_openssl_mgt.c b/src/lib/crypt_ops/crypto_openssl_mgt.c
index 065cbca1cc..e763491a11 100644
--- src/lib/crypt_ops/crypto_openssl_mgt.c.orig
+++ src/lib/crypt_ops/crypto_openssl_mgt.c
@@ -222,7 +222,7 @@ crypto_openssl_early_init(void)
 
     setup_openssl_threading();
 
-    unsigned long version_num = OpenSSL_version_num();
+    unsigned long version_num = tor_OpenSSL_version_num();
     const char *version_str = crypto_openssl_get_version_str();
     if (version_num == OPENSSL_VERSION_NUMBER &&
         !strcmp(version_str, OPENSSL_VERSION_TEXT)) {
diff --git a/src/lib/tls/tortls_openssl.c b/src/lib/tls/tortls_openssl.c
index 2269714141..ad9b49ab4f 100644
--- src/lib/tls/tortls_openssl.c.orig
+++ src/lib/tls/tortls_openssl.c
@@ -342,7 +342,7 @@ tor_tls_init(void)
 
 #if (SIZEOF_VOID_P >= 8 &&                              \
      OPENSSL_VERSION_NUMBER >= OPENSSL_V_SERIES(1,0,1))
-    long version = OpenSSL_version_num();
+    long version = tor_OpenSSL_version_num();
 
     /* LCOV_EXCL_START : we can't test these lines on the same machine */
     if (version >= OPENSSL_V_SERIES(1,0,1)) {
