--- third_party/boringssl/src/crypto/fipsmodule/sha/asm/sha512-x86_64.pl.orig	2023-07-16 15:47:57 UTC
+++ third_party/boringssl/src/crypto/fipsmodule/sha/asm/sha512-x86_64.pl
@@ -263,6 +263,7 @@ $code=<<___;
 .align	16
 $func:
 .cfi_startproc
+	_CET_ENDBR
 ___
 $code.=<<___ if ($SZ==4 || $avx);
 	leaq	OPENSSL_ia32cap_P(%rip),%r11
