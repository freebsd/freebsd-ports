--- src/3rdparty/chromium/third_party/boringssl/src/crypto/refcount_c11.c.orig	2022-09-24 10:57:32 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/refcount_c11.c
@@ -22,6 +22,9 @@
 #include <stdatomic.h>
 #include <stdlib.h>
 
+#if !defined(__cplusplus) && !defined(static_assert)
+#define static_assert _Static_assert
+#endif
 
 // See comment above the typedef of CRYPTO_refcount_t about these tests.
 static_assert(alignof(CRYPTO_refcount_t) == alignof(_Atomic CRYPTO_refcount_t),
