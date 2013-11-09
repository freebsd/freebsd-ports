--- libavutil/x86/asm.h.orig	2013-11-07 22:15:35.000000000 +0100
+++ libavutil/x86/asm.h	2013-11-07 22:15:52.000000000 +0100
@@ -68,7 +68,7 @@
 typedef int x86_reg;
 #endif
 
-#define HAVE_7REGS (ARCH_X86_64 || (HAVE_EBX_AVAILABLE && HAVE_EBP_AVAILABLE))
+#define HAVE_7REGS (ARCH_X86_64 || (HAVE_EBX_AVAILABLE && HAVE_EBP_AVAILABLE && !defined(__clang__)))
 #define HAVE_6REGS (ARCH_X86_64 || (HAVE_EBX_AVAILABLE || HAVE_EBP_AVAILABLE))
 
 #if ARCH_X86_64 && defined(PIC)
