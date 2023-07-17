--- third_party/boringssl/src/crypto/fipsmodule/modes/asm/ghash-x86_64.pl.orig	2023-07-16 15:47:57 UTC
+++ third_party/boringssl/src/crypto/fipsmodule/modes/asm/ghash-x86_64.pl
@@ -206,6 +206,7 @@ $code.=<<___;
 gcm_init_clmul:
 .cfi_startproc
 .seh_startproc
+	_CET_ENDBR
 .L_init_clmul:
 ___
 $code.=<<___ if ($win64);
@@ -288,6 +289,7 @@ $code.=<<___;
 .align	16
 gcm_gmult_clmul:
 .cfi_startproc
+	_CET_ENDBR
 .L_gmult_clmul:
 	movdqu		($Xip),$Xi
 	movdqa		.Lbswap_mask(%rip),$T3
@@ -340,6 +342,7 @@ $code.=<<___;
 gcm_ghash_clmul:
 .cfi_startproc
 .seh_startproc
+	_CET_ENDBR
 .L_ghash_clmul:
 ___
 $code.=<<___ if ($win64);
@@ -708,6 +711,7 @@ $code.=<<___;
 .align	32
 gcm_init_avx:
 .cfi_startproc
+	_CET_ENDBR
 ___
 if ($avx) {
 my ($Htbl,$Xip)=@_4args;
@@ -853,6 +857,7 @@ $code.=<<___;
 .align	32
 gcm_gmult_avx:
 .cfi_startproc
+	_CET_ENDBR
 	jmp	.L_gmult_clmul
 .cfi_endproc
 .size	gcm_gmult_avx,.-gcm_gmult_avx
@@ -864,6 +869,7 @@ $code.=<<___;
 .align	32
 gcm_ghash_avx:
 .cfi_startproc
+	_CET_ENDBR
 ___
 if ($avx) {
 my ($Xip,$Htbl,$inp,$len)=@_4args;
