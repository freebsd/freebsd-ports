--- src/3rdparty/chromium/third_party/boringssl/src/crypto/cipher_extra/asm/aes128gcmsiv-x86_64.pl.orig	2023-02-08 09:03:45 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/cipher_extra/asm/aes128gcmsiv-x86_64.pl
@@ -32,7 +32,7 @@ open OUT,"| \"$^X\" \"$xlate\" $flavour \"$output\"";
 *STDOUT=*OUT;
 
 $code.=<<___;
-.data
+.rodata
 
 .align 16
 one:
@@ -66,6 +66,7 @@ con3:
 .byte -1,-1,-1,-1,-1,-1,-1,-1,4,5,6,7,4,5,6,7
 and_mask:
 .long 0,0xffffffff, 0xffffffff, 0xffffffff
+.previous
 ___
 
 $code.=<<___;
