--- arm/v6/aes-encrypt-internal.asm.orig	2016-01-27 11:50:13.588690000 +0100
+++ arm/v6/aes-encrypt-internal.asm	2016-01-27 11:50:16.922229000 +0100
@@ -65,7 +65,7 @@ C 8 saved registers
 define(<FRAME_DST>,  <[sp, #+40]>)
 define(<FRAME_SRC>,  <[sp, #+44]>)
 
-define(<SRC>, <%r12>)	C Overlap registers used in inner loop.
+define(<SRC>, <r12>)	C Overlap registers used in inner loop.
 define(<DST>, <COUNT>)
 
 C 53 instr.
