--- third_party/boringssl/src/crypto/fipsmodule/modes/asm/ghash-ssse3-x86_64.pl.orig	2023-07-21 09:49:17 UTC
+++ third_party/boringssl/src/crypto/fipsmodule/modes/asm/ghash-ssse3-x86_64.pl
@@ -104,6 +104,7 @@ my $code = <<____;
 gcm_gmult_ssse3:
 .cfi_startproc
 .seh_startproc
+	_CET_ENDBR
 ____
 $code .= <<____ if ($win64);
 	subq	\$40, %rsp
@@ -246,6 +247,7 @@ $code .= <<____;
 gcm_ghash_ssse3:
 .cfi_startproc
 .seh_startproc
+	_CET_ENDBR
 ____
 $code .= <<____ if ($win64);
 	subq	\$56, %rsp
