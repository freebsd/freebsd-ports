--- ffmpeg/libavutil/x86_cpu.h.orig	2010-10-06 03:26:13.000000000 +0200
+++ ffmpeg/libavutil/x86_cpu.h	2010-11-04 21:01:40.581647958 +0100
@@ -71,7 +71,7 @@
 #define HAVE_7REGS (ARCH_X86_64 || (HAVE_EBX_AVAILABLE && HAVE_EBP_AVAILABLE))
 #define HAVE_6REGS (ARCH_X86_64 || (HAVE_EBX_AVAILABLE || HAVE_EBP_AVAILABLE))
 
-#if ARCH_X86_64 && defined(PIC)
+#if ARCH_X86_64
 #    define BROKEN_RELOCATIONS 1
 #endif
 
