--- third_party/boringssl/src/crypto/fipsmodule/ec/asm/p256-x86_64-asm.pl.orig	2023-07-21 09:49:17 UTC
+++ third_party/boringssl/src/crypto/fipsmodule/ec/asm/p256-x86_64-asm.pl
@@ -98,6 +98,7 @@ $code.=<<___;
 .align	32
 ecp_nistz256_neg:
 .cfi_startproc
+	_CET_ENDBR
 	push	%r12
 .cfi_push	%r12
 	push	%r13
@@ -166,6 +167,7 @@ $code.=<<___;
 .align	32
 ecp_nistz256_ord_mul_mont:
 .cfi_startproc
+	_CET_ENDBR
 ___
 $code.=<<___	if ($addx);
 	leaq	OPENSSL_ia32cap_P(%rip), %rcx
@@ -497,6 +499,7 @@ $code.=<<___;
 .align	32
 ecp_nistz256_ord_sqr_mont:
 .cfi_startproc
+	_CET_ENDBR
 ___
 $code.=<<___	if ($addx);
 	leaq	OPENSSL_ia32cap_P(%rip), %rcx
@@ -1247,6 +1250,7 @@ $code.=<<___;
 .align	32
 ecp_nistz256_mul_mont:
 .cfi_startproc
+	_CET_ENDBR
 ___
 $code.=<<___	if ($addx);
 	leaq	OPENSSL_ia32cap_P(%rip), %rcx
@@ -1549,6 +1553,7 @@ __ecp_nistz256_mul_montq:
 .align	32
 ecp_nistz256_sqr_mont:
 .cfi_startproc
+	_CET_ENDBR
 ___
 $code.=<<___	if ($addx);
 	leaq	OPENSSL_ia32cap_P(%rip), %rcx
@@ -2098,6 +2103,7 @@ $code.=<<___;
 .align	32
 ecp_nistz256_select_w5:
 .cfi_startproc
+	_CET_ENDBR
 ___
 $code.=<<___	if ($avx>1);
 	leaq	OPENSSL_ia32cap_P(%rip), %rax
@@ -2198,6 +2204,7 @@ $code.=<<___;
 .align	32
 ecp_nistz256_select_w7:
 .cfi_startproc
+	_CET_ENDBR
 ___
 $code.=<<___	if ($avx>1);
 	leaq	OPENSSL_ia32cap_P(%rip), %rax
@@ -2403,6 +2410,7 @@ $code.=<<___;
 ecp_nistz256_avx2_select_w7:
 .cfi_startproc
 .Lavx2_select_w7:
+	_CET_ENDBR
 	vzeroupper
 ___
 $code.=<<___	if ($win64);
@@ -2514,6 +2522,7 @@ $code.=<<___;
 .type	ecp_nistz256_avx2_select_w7,\@function,3
 .align	32
 ecp_nistz256_avx2_select_w7:
+	_CET_ENDBR
 	.byte	0x0f,0x0b	# ud2
 	ret
 .size	ecp_nistz256_avx2_select_w7,.-ecp_nistz256_avx2_select_w7
@@ -2718,6 +2727,7 @@ $code.=<<___;
 .align	32
 ecp_nistz256_point_double:
 .cfi_startproc
+	_CET_ENDBR
 ___
 $code.=<<___	if ($addx);
 	leaq	OPENSSL_ia32cap_P(%rip), %rcx
@@ -2970,6 +2980,7 @@ $code.=<<___;
 .align	32
 ecp_nistz256_point_add:
 .cfi_startproc
+	_CET_ENDBR
 ___
 $code.=<<___	if ($addx);
 	leaq	OPENSSL_ia32cap_P(%rip), %rcx
@@ -3368,6 +3379,7 @@ $code.=<<___;
 .align	32
 ecp_nistz256_point_add_affine:
 .cfi_startproc
+	_CET_ENDBR
 ___
 $code.=<<___	if ($addx);
 	leaq	OPENSSL_ia32cap_P(%rip), %rcx
