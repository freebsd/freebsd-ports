--- src/OpaqueVal.cc.orig	2026-05-12 18:14:44 UTC
+++ src/OpaqueVal.cc
@@ -27,7 +27,8 @@
 #include "zeek/probabilistic/BloomFilter.h"
 #include "zeek/probabilistic/CardinalityCounter.h"
 
-#if ( OPENSSL_VERSION_NUMBER < 0x10100000L ) || defined(LIBRESSL_VERSION_NUMBER)
+#if ( OPENSSL_VERSION_NUMBER < 0x10100000L ) ||                                                                        \
+    (defined(LIBRESSL_VERSION_NUMBER) && (LIBRESSL_VERSION_NUMBER < 0x30900000L))
 inline void* EVP_MD_CTX_md_data(const EVP_MD_CTX* ctx) { return ctx->md_data; }
 #endif
 
