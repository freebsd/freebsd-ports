--- tools/depends/target/ffmpeg/FFmpeg-3.1.6-Krypton/libavutil/x86/asm.h	2016-10-08 UTC
+++ tools/depends/target/ffmpeg/FFmpeg-3.1.6-Krypton/libavutil/x86/asm.h.orig
@@ -72,7 +72,7 @@ typedef int32_t x86_reg;
 typedef int x86_reg;
 #endif
 
-#define HAVE_7REGS (ARCH_X86_64 || (HAVE_EBX_AVAILABLE && HAVE_EBP_AVAILABLE))
+#define HAVE_7REGS (ARCH_X86_64 || (HAVE_EBX_AVAILABLE && HAVE_EBP_AVAILABLE && !defined(__clang__)))
 #define HAVE_6REGS (ARCH_X86_64 || (HAVE_EBX_AVAILABLE || HAVE_EBP_AVAILABLE))
 
 #if ARCH_X86_64 && defined(PIC)
