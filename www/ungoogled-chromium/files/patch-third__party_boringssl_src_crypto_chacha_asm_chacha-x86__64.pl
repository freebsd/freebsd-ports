--- third_party/boringssl/src/crypto/chacha/asm/chacha-x86_64.pl.orig	2023-07-21 09:49:17 UTC
+++ third_party/boringssl/src/crypto/chacha/asm/chacha-x86_64.pl
@@ -231,6 +231,7 @@ $code.=<<___;
 .align	64
 ChaCha20_ctr32:
 .cfi_startproc
+	_CET_ENDBR
 	cmp	\$0,$len
 	je	.Lno_data
 	mov	OPENSSL_ia32cap_P+4(%rip),%r10
