--- src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/modes/asm/ghash-ssse3-x86_64.pl.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/modes/asm/ghash-ssse3-x86_64.pl
@@ -331,6 +331,7 @@ $code .= <<____;
 .seh_endproc
 .size	gcm_ghash_ssse3,.-gcm_ghash_ssse3
 
+.rodata
 .align	16
 # .Lreverse_bytes is a permutation which, if applied with pshufb, reverses the
 # bytes in an XMM register.
@@ -339,6 +340,7 @@ $code .= <<____;
 # .Llow4_mask is an XMM mask which selects the low four bits of each byte.
 .Llow4_mask:
 .quad	0x0f0f0f0f0f0f0f0f, 0x0f0f0f0f0f0f0f0f
+.previous
 ____
 
 print $code;
