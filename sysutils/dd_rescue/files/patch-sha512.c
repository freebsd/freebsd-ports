--- sha512.c.orig	2023-02-23 21:51:27 UTC
+++ sha512.c
@@ -13,13 +13,14 @@
 #endif
 
 #include "sha512.h"
+#include "ffs.h"
 #include <stdint.h>
 #include <stdio.h>
 #include <string.h>
 #include <netinet/in.h>
 #include <assert.h>
 #include <unistd.h>
-#include <endian.h>
+#include <machine/endian.h>
 
 /*
 Note 1: All variables are 64 bit unsigned integers and addition is calculated modulo 2^64 
@@ -138,7 +139,7 @@ void sha512_128(const uint8_t* msg, hash_t* ctx)
 #endif
 #endif
 	/* Extend the first 16 words into the remaining 48 words w[16..63] of the message schedule array: */
-	for (int i = 16; i < 80;  ++i) {
+	for (i = 16; i < 80;  ++i) {
 		const uint64_t s0 = RIGHTROTATE(w[i-15], 1) ^ RIGHTROTATE(w[i-15], 8) ^ (w[i-15] >> 7);
 		const uint64_t s1 = RIGHTROTATE(w[i-2], 19) ^ RIGHTROTATE(w[i-2] ,61) ^ (w[i-2]  >> 6);
 		w[i] = w[i-16] + s0 + w[i-7] + s1;
@@ -147,7 +148,7 @@ void sha512_128(const uint8_t* msg, hash_t* ctx)
 	uint64_t a = ctx->sha512_h[0], b = ctx->sha512_h[1], c = ctx->sha512_h[2], d = ctx->sha512_h[3];
 	uint64_t e = ctx->sha512_h[4], f = ctx->sha512_h[5], g = ctx->sha512_h[6], h = ctx->sha512_h[7];
 	/* Compression function main loop: */
-	for (int i = 0; i < 80; ++i) {
+	for (i = 0; i < 80; ++i) {
 		const uint64_t S1 = RIGHTROTATE(e, 14) ^ RIGHTROTATE(e, 18) ^ RIGHTROTATE(e, 41);
 		//const uint64_t ch = (e & f) ^ ((~e) & g);
 		const uint64_t ch = g ^ (e & (f ^ g));
