--- src/common/crc32c_ppc_fast_zero_asm.S.orig	2020-08-10 22:15:22.000000000 +0200
+++ src/common/crc32c_ppc_fast_zero_asm.S	2021-01-03 01:06:00.563321000 +0100
@@ -1,6 +1,6 @@
 /*
  * Use the fixed point version of Barrett reduction to compute a mod n
- * over GF(2) for given n using POWER8 instructions. We use k = 32.
+ * over GF(2) for n = 0x104c11db7 using POWER8 instructions. We use k = 32.
  *
  * http://en.wikipedia.org/wiki/Barrett_reduction
  *
@@ -14,33 +14,39 @@
  *     any later version, or
  *  b) the Apache License, Version 2.0
  */
-#include <ppc-asm.h>
-#include "common/ppc-opcode.h"
 
-#undef toc
-
-#ifndef r1
-#define r1 1
+#if defined (__clang__)
+#ifndef __ALTIVEC__
+#define __ALTIVEC__
 #endif
-
-#ifndef r2
-#define r2 2
+#include "ppc-asm.h"
+#else
+#include <ppc-asm.h>
 #endif
+#include "ppc-opcode.h"
 
 	.section	.data
 .balign 16
-
-.barrett_fz_constants:
+.constants:
 	/* Barrett constant m - (4^32)/n */
-	.octa 0x0000000000000000000000011f91caf6	/* x^64 div p(x) */
+	.octa 0x00000000000000000000000104d101df
+
 	/* Barrett constant n */
-	.octa 0x0000000000000000000000011edc6f41
+	.octa 0x00000000000000000000000104c11db7
 
-.text
+.bit_reflected_constants:
+	/* 33 bit reflected Barrett constant m - (4^32)/n */
+	.octa 0x000000000000000000000001f7011641
+
+	/* 33 bit reflected Barrett constant n */
+	.octa 0x000000000000000000000001db710641
+
+	.text
+
 /* unsigned int barrett_reduction(unsigned long val) */
 FUNC_START(barrett_reduction)
-	addis	r4,r2,.barrett_fz_constants@toc@ha
-	addi	r4,r4,.barrett_fz_constants@toc@l
+	lis	r4,.constants@ha
+	la	r4,.constants@l(r4)
 
 	li	r5,16
 	vxor	v1,v1,v1	/* zero v1 */
@@ -74,4 +80,47 @@
 
 	blr
 FUNC_END(barrett_reduction)
-	
+
+/* unsigned int barrett_reduction_reflected(unsigned long val) */
+FUNC_START(barrett_reduction_reflected)
+	lis	r4,.bit_reflected_constants@ha
+	la	r4,.bit_reflected_constants@l(r4)
+
+	li	r5,16
+	vxor	v1,v1,v1	/* zero v1 */
+
+	/* Get a into v0 */
+	MTVRD(v0, r3)
+	vsldoi	v0,v1,v0,8	/* shift into bottom 64 bits, this is a */
+
+	/* Load constants */
+	lvx	v2,0,r4		/* m */
+	lvx	v3,r5,r4	/* n */
+
+	vspltisw v5,-1		/* all ones */
+	vsldoi	v6,v1,v5,4	/* bitmask with low 32 bits set */
+
+	/*
+	 * Now for the Barrett reduction algorithm. Instead of bit reflecting
+	 * our data (which is expensive to do), we bit reflect our constants
+	 * and our algorithm, which means the intermediate data in our vector
+	 * registers goes from 0-63 instead of 63-0. We can reflect the
+	 * algorithm because we don't carry in mod 2 arithmetic.
+	 */
+	vand	v4,v0,v6	/* bottom 32 bits of a */
+	VPMSUMD(v4,v4,v2)	/* ma */
+	vand	v4,v4,v6	/* bottom 32bits of ma */
+	VPMSUMD(v4,v4,v3)	/* qn */
+	vxor	v0,v0,v4	/* a - qn, subtraction is xor in GF(2) */
+
+	/*
+	 * Since we are bit reflected, the result (ie the low 32 bits) is in the
+	 * high 32 bits. We just need to shift it left 4 bytes
+	 * V0 [ 0 1 X 3 ]
+	 * V0 [ 0 X 2 3 ]
+	 */
+	vsldoi	v0,v0,v1,4	/* shift result into top 64 bits of v0 */
+	MFVRD(r3, v0)
+
+	blr
+FUNC_END(barrett_reduction_reflected)
