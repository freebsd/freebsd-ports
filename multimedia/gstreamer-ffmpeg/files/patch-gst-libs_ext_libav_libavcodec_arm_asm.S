--- gst-libs/ext/libav/libavcodec/arm/asm.S.orig	2013-02-02 09:03:32 UTC
+++ gst-libs/ext/libav/libavcodec/arm/asm.S
@@ -39,7 +39,6 @@ ELF     .eabi_attribute 25, \val
 .macro  function name, export=0
     .macro endfunc
 ELF     .size   \name, . - \name
-        .endfunc
         .purgem endfunc
     .endm
         .text
@@ -48,8 +47,9 @@ ELF     .size   \name, . - \name
 EXTERN_ASM\name:
     .endif
 ELF     .type   \name, %function
-        .func   \name
+    .if \export == 0
 \name:
+    .endif
 .endm
 
 .macro  const   name, align=2
