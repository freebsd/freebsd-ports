--- cargo-crates/openssl-sys-0.9.60/build/expando.c.orig	2020-12-24 04:59:50.000000000 -0800
+++ cargo-crates/openssl-sys-0.9.60/build/expando.c	2025-12-05 10:10:37.241319000 -0800
@@ -1,12 +1,18 @@
 #include <openssl/opensslv.h>
 #include <openssl/opensslconf.h>
 
+/* OpenSSL 3.x defines OPENSSL_VERSION_NUMBER with an 'L' suffix which breaks token pasting.
+ * Detect OpenSSL 3.x and output the version directly. */
+#if defined(OPENSSL_VERSION_MAJOR) && OPENSSL_VERSION_MAJOR >= 3
+/* OpenSSL 3.x - emit identifier and hex value separately */
+RUST_VERSION_OPENSSL_0x30000000L
+#elif defined(LIBRESSL_VERSION_NUMBER)
 #define VERSION2(n, v) RUST_VERSION_##n##_##v
 #define VERSION(n, v) VERSION2(n, v)
-
-#ifdef LIBRESSL_VERSION_NUMBER
 VERSION(LIBRESSL, LIBRESSL_VERSION_NUMBER)
 #else
+#define VERSION2(n, v) RUST_VERSION_##n##_##v
+#define VERSION(n, v) VERSION2(n, v)
 VERSION(OPENSSL, OPENSSL_VERSION_NUMBER)
 #endif
 
