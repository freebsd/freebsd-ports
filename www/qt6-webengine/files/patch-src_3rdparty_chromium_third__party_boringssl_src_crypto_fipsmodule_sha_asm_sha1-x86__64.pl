--- src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/sha/asm/sha1-x86_64.pl.orig	2023-02-08 09:03:45 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/sha/asm/sha1-x86_64.pl
@@ -1815,6 +1815,7 @@ ___
 }
 }
 $code.=<<___;
+.rodata
 .align	64
 K_XX_XX:
 .long	0x5a827999,0x5a827999,0x5a827999,0x5a827999	# K_00_19
@@ -1833,6 +1834,7 @@ ___
 $code.=<<___;
 .asciz	"SHA1 block transform for x86_64, CRYPTOGAMS by <appro\@openssl.org>"
 .align	64
+.previous
 ___
 
 # EXCEPTION_DISPOSITION handler (EXCEPTION_RECORD *rec,ULONG64 frame,
