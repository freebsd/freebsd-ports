--- third_party/boringssl/src/crypto/fipsmodule/bn/asm/x86_64-mont.pl.orig	2023-07-21 09:49:17 UTC
+++ third_party/boringssl/src/crypto/fipsmodule/bn/asm/x86_64-mont.pl
@@ -92,6 +92,7 @@ $code=<<___;
 .align	16
 bn_mul_mont:
 .cfi_startproc
+	_CET_ENDBR
 	mov	${num}d,${num}d
 	mov	%rsp,%rax
 .cfi_def_cfa_register	%rax
