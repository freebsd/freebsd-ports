--- third_party/boringssl/src/crypto/fipsmodule/sha/asm/sha1-x86_64.pl.orig	2023-07-16 15:47:57 UTC
+++ third_party/boringssl/src/crypto/fipsmodule/sha/asm/sha1-x86_64.pl
@@ -244,6 +244,7 @@ $code.=<<___;
 .align	16
 sha1_block_data_order:
 .cfi_startproc
+	_CET_ENDBR
 	leaq	OPENSSL_ia32cap_P(%rip),%r10
 	mov	0(%r10),%r9d
 	mov	4(%r10),%r8d
