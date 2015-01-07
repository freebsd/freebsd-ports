--- common/arm/asm.S.orig	2014-08-27 20:45:08 UTC
+++ common/arm/asm.S
@@ -40,6 +40,12 @@
 #   define ELF @
 #endif
 
+#if HAVE_AS_FUNC
+#   define FUNC
+#else
+#   define FUNC @
+#endif
+
 .macro require8, val=1
 ELF     .eabi_attribute 24, \val
 .endm
@@ -49,17 +55,22 @@ ELF     .eabi_attribute 25, \val
 .endm
 
 .macro function name, export=1
+    .macro endfunc
+ELF     .size   \name, . - \name
+FUNC    .endfunc
+        .purgem endfunc
+    .endm
         .align  2
 .if \export == 1
         .global EXTERN_ASM\name
 ELF     .hidden EXTERN_ASM\name
 ELF     .type   EXTERN_ASM\name, %function
-        .func   EXTERN_ASM\name
+FUNC    .func   EXTERN_ASM\name
 EXTERN_ASM\name:
 .else
 ELF     .hidden \name
 ELF     .type   \name, %function
-        .func   \name
+FUNC    .func   \name
 \name:
 .endif
 .endm
