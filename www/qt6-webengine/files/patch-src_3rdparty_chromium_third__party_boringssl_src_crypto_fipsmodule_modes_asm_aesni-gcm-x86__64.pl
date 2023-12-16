--- src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/modes/asm/aesni-gcm-x86_64.pl.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/modes/asm/aesni-gcm-x86_64.pl
@@ -1053,6 +1053,7 @@ $code.=<<___;
 ___
 
 $code.=<<___;
+.rodata
 .align	64
 .Lbswap_mask:
 	.byte	15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0
@@ -1066,6 +1067,7 @@ $code.=<<___;
 	.byte	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
 .asciz	"AES-NI GCM module for x86_64, CRYPTOGAMS by <appro\@openssl.org>"
 .align	64
+.previous
 ___
 }}} else {{{
 $code=<<___;	# assembler is too old
