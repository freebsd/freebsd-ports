--- sha256.c.orig	2024-02-17 15:17:02 UTC
+++ sha256.c
@@ -108,7 +108,7 @@ void sha256_64(const uint8_t* msg, hash_t* ctx)
 #endif
 #endif
 	/* Extend the first 16 words into the remaining 48 words w[16..63] of the message schedule array: */
-	for (int i = 16; i < 64;  ++i) {
+	for (i = 16; i < 64;  ++i) {
 		const uint32_t s0 = RIGHTROTATE(w[i-15], 7) ^ RIGHTROTATE(w[i-15], 18) ^ (w[i-15] >> 3);
 		const uint32_t s1 = RIGHTROTATE(w[i-2], 17) ^ RIGHTROTATE(w[i-2] , 19) ^ (w[i-2] >> 10);
 		w[i] = w[i-16] + s0 + w[i-7] + s1;
@@ -117,7 +117,7 @@ void sha256_64(const uint8_t* msg, hash_t* ctx)
 	uint32_t a = ctx->sha256_h[0], b = ctx->sha256_h[1], c = ctx->sha256_h[2], d = ctx->sha256_h[3];
 	uint32_t e = ctx->sha256_h[4], f = ctx->sha256_h[5], g = ctx->sha256_h[6], h = ctx->sha256_h[7];
 	/* Compression function main loop: */
-	for (int i = 0; i < 64; ++i) {
+	for (i = 0; i < 64; ++i) {
 		const uint32_t S1 = RIGHTROTATE(e, 6) ^ RIGHTROTATE(e, 11) ^ RIGHTROTATE(e, 25);
 		//const uint32_t ch = (e & f) ^ ((~e) & g);
 		const uint32_t ch = g ^ (e & (f ^ g));
