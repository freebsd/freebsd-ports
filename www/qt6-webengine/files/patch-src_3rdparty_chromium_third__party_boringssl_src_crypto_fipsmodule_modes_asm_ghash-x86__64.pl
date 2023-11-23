--- src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/modes/asm/ghash-x86_64.pl.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/modes/asm/ghash-x86_64.pl
@@ -1297,6 +1297,7 @@ ___
 }
 
 $code.=<<___;
+.rodata
 .align	64
 .Lbswap_mask:
 	.byte	15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0
@@ -1308,6 +1309,7 @@ $code.=<<___;
 
 .asciz	"GHASH for x86_64, CRYPTOGAMS by <appro\@openssl.org>"
 .align	64
+.previous
 ___
 
 $code =~ s/\`([^\`]*)\`/eval($1)/gem;
