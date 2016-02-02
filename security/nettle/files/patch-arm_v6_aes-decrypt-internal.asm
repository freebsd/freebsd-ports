--- arm/v6/aes-decrypt-internal.asm.orig	2016-01-27 11:50:06.979110000 +0100
+++ arm/v6/aes-decrypt-internal.asm	2016-01-27 11:50:10.594660000 +0100
@@ -59,7 +59,7 @@ C 8 saved registers
 define(<FRAME_DST>,  <[sp, #+40]>)
 define(<FRAME_SRC>,  <[sp, #+44]>)
 
-define(<SRC>, <%r12>)	C Overlap registers used in inner loop.
+define(<SRC>, <r12>)	C Overlap registers used in inner loop.
 define(<DST>, <COUNT>)
 
 C AES_DECRYPT_ROUND(x0,x1,x2,x3,w0,w1,w2,w3,key)
