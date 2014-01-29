--- ./lib/ffmpeg/libavutil/x86/asm.h.orig	2014-01-01 02:26:03.000000000 +0000
+++ ./lib/ffmpeg/libavutil/x86/asm.h	2014-01-12 10:28:23.000000000 +0000
@@ -68,7 +68,7 @@
 typedef int x86_reg;
 #endif
 
-#define HAVE_7REGS (ARCH_X86_64 || (HAVE_EBX_AVAILABLE && HAVE_EBP_AVAILABLE))
+#define HAVE_7REGS (ARCH_X86_64 || (HAVE_EBX_AVAILABLE && HAVE_EBP_AVAILABLE && !defined(__clang__)))
 #define HAVE_6REGS (ARCH_X86_64 || (HAVE_EBX_AVAILABLE || HAVE_EBP_AVAILABLE))
 
 #if ARCH_X86_64 && defined(PIC)
