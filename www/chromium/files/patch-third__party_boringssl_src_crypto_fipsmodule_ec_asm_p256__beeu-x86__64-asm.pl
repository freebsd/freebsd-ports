--- third_party/boringssl/src/crypto/fipsmodule/ec/asm/p256_beeu-x86_64-asm.pl.orig	2023-07-16 15:47:57 UTC
+++ third_party/boringssl/src/crypto/fipsmodule/ec/asm/p256_beeu-x86_64-asm.pl
@@ -154,6 +154,7 @@ $code.=<<___;
 .align 32
 beeu_mod_inverse_vartime:
 .cfi_startproc
+    _CET_ENDBR
     push %rbp
 .cfi_push rbp
     push %r12
