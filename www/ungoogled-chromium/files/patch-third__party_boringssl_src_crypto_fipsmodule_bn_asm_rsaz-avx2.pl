--- third_party/boringssl/src/crypto/fipsmodule/bn/asm/rsaz-avx2.pl.orig	2023-07-21 09:49:17 UTC
+++ third_party/boringssl/src/crypto/fipsmodule/bn/asm/rsaz-avx2.pl
@@ -112,6 +112,7 @@ $code.=<<___;
 .align	64
 rsaz_1024_sqr_avx2:		# 702 cycles, 14% faster than rsaz_1024_mul_avx2
 .cfi_startproc
+	_CET_ENDBR
 	lea	(%rsp), %rax
 .cfi_def_cfa_register	%rax
 	push	%rbx
@@ -863,6 +864,7 @@ $code.=<<___;
 .align	64
 rsaz_1024_mul_avx2:
 .cfi_startproc
+	_CET_ENDBR
 	lea	(%rsp), %rax
 .cfi_def_cfa_register	%rax
 	push	%rbx
@@ -1474,6 +1476,7 @@ $code.=<<___;
 .align	32
 rsaz_1024_red2norm_avx2:
 .cfi_startproc
+	_CET_ENDBR
 	sub	\$-128,$inp	# size optimization
 	xor	%rax,%rax
 ___
@@ -1515,6 +1518,7 @@ $code.=<<___;
 .align	32
 rsaz_1024_norm2red_avx2:
 .cfi_startproc
+	_CET_ENDBR
 	sub	\$-128,$out	# size optimization
 	mov	($inp),@T[0]
 	mov	\$0x1fffffff,%eax
@@ -1559,6 +1563,7 @@ $code.=<<___;
 .align	32
 rsaz_1024_scatter5_avx2:
 .cfi_startproc
+	_CET_ENDBR
 	vzeroupper
 	vmovdqu	.Lscatter_permd(%rip),%ymm5
 	shl	\$4,$power
@@ -1586,6 +1591,7 @@ rsaz_1024_scatter5_avx2:
 .align	32
 rsaz_1024_gather5_avx2:
 .cfi_startproc
+	_CET_ENDBR
 	vzeroupper
 	mov	%rsp,%r11
 .cfi_def_cfa_register	%r11
