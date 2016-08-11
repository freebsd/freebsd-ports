--- tools/depends/target/ffmpeg/FFmpeg-2.8.6-Jarvis-16.0/libavutil/x86/asm.h.orig	2016-02-03 20:33:07 UTC
+++ tools/depends/target/ffmpeg/FFmpeg-2.8.6-Jarvis-16.0/libavutil/x86/asm.h
@@ -72,7 +72,7 @@ typedef int32_t x86_reg;
 typedef int x86_reg;
 #endif
 
-#define HAVE_7REGS (ARCH_X86_64 || (HAVE_EBX_AVAILABLE && HAVE_EBP_AVAILABLE))
+#define HAVE_7REGS (ARCH_X86_64 || (HAVE_EBX_AVAILABLE && HAVE_EBP_AVAILABLE && !defined(__clang__)))
 #define HAVE_6REGS (ARCH_X86_64 || (HAVE_EBX_AVAILABLE || HAVE_EBP_AVAILABLE))
 
 #if ARCH_X86_64 && defined(PIC)
