--- src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/bn/asm/x86_64-mont5.pl.orig	2023-02-08 09:03:45 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/bn/asm/x86_64-mont5.pl
@@ -3576,11 +3576,13 @@ $code.=<<___;
 ___
 }
 $code.=<<___;
+.rodata
 .align	64
 .Linc:
 	.long	0,0, 1,1
 	.long	2,2, 2,2
 .asciz	"Montgomery Multiplication with scatter/gather for x86_64, CRYPTOGAMS by <appro\@openssl.org>"
+.previous
 ___
 
 # EXCEPTION_DISPOSITION handler (EXCEPTION_RECORD *rec,ULONG64 frame,
