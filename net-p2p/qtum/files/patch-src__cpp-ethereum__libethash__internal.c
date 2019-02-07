--- src/cpp-ethereum/libethash/internal.c.orig	2019-02-07 09:02:35.787808000 +0100
+++ src/cpp-ethereum/libethash/internal.c	2019-02-07 09:06:32.651306000 +0100
@@ -328,7 +328,7 @@
 void ethash_quick_hash(
 	ethash_h256_t* return_hash,
 	ethash_h256_t const* header_hash,
-	uint64_t const nonce,
+	uint64_t nonce,
 	ethash_h256_t const* mix_hash
 )
 {
