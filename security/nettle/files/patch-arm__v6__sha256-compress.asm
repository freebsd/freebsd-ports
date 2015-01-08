--- arm/v6/sha256-compress.asm.orig	2013-05-28 16:21:54.000000000 +0200
+++ arm/v6/sha256-compress.asm	2015-01-04 00:39:14.000000000 +0100
@@ -112,7 +112,7 @@ define(<NOEXPN>, <
 PROLOGUE(_nettle_sha256_compress)
 	push	{r4,r5,r6,r7,r8,r10,r11,r14}
 	sub	sp, sp, #68
-	str	STATE, [sp, +#64]
+	str	STATE, [sp, #+64]
 
 	C Load data up front, since we don't have enough registers
 	C to load and shift on-the-fly
@@ -185,7 +185,7 @@ PROLOGUE(_nettle_sha256_compress)
 	EXPN(15) ROUND(SB,SC,SD,SE,SF,SG,SH,SA)
 	bne	.Loop2
 
-	ldr	STATE, [sp, +#64]
+	ldr	STATE, [sp, #+64]
 	C No longer needed registers
 	ldm	STATE, {r1,r2,r12,r14}
 	add	SA, SA, r1
