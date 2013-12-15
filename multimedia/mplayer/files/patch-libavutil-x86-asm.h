--- ffmpeg/libavutil/x86/asm.h.orig	2013-05-25 19:20:04.000000000 +0200
+++ ffmpeg/libavutil/x86/asm.h	2013-11-11 21:51:57.940269764 +0100
@@ -70,7 +70,7 @@
 typedef int x86_reg;
 #endif
 
-#define HAVE_7REGS (ARCH_X86_64 || (HAVE_EBX_AVAILABLE && HAVE_EBP_AVAILABLE))
+#define HAVE_7REGS (ARCH_X86_64)
 #define HAVE_6REGS (ARCH_X86_64 || (HAVE_EBX_AVAILABLE || HAVE_EBP_AVAILABLE))
 
 #if ARCH_X86_64 && defined(PIC)
