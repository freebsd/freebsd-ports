--- src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/sha/asm/sha512-x86_64.pl.orig	2023-02-08 09:03:45 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/sha/asm/sha512-x86_64.pl
@@ -404,6 +404,7 @@ ___
 
 if ($SZ==4) {
 $code.=<<___;
+.rodata
 .align	64
 .type	$TABLE,\@object
 $TABLE:
@@ -447,9 +448,11 @@ $TABLE:
 	.long	0xffffffff,0xffffffff,0x03020100,0x0b0a0908
 	.long	0xffffffff,0xffffffff,0x03020100,0x0b0a0908
 	.asciz	"SHA256 block transform for x86_64, CRYPTOGAMS by <appro\@openssl.org>"
+.previous
 ___
 } else {
 $code.=<<___;
+.rodata
 .align	64
 .type	$TABLE,\@object
 $TABLE:
@@ -537,6 +540,7 @@ $TABLE:
 	.quad	0x0001020304050607,0x08090a0b0c0d0e0f
 	.quad	0x0001020304050607,0x08090a0b0c0d0e0f
 	.asciz	"SHA512 block transform for x86_64, CRYPTOGAMS by <appro\@openssl.org>"
+.previous
 ___
 }
 
