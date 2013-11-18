--- external/FFmpeg/libavcodec/x86/ac3dsp_init.c.orig	2013-09-18 20:06:08.000000000 +0000
+++ external/FFmpeg/libavcodec/x86/ac3dsp_init.c	2013-10-18 11:58:01.000000000 +0000
@@ -51,7 +51,7 @@
 extern void ff_ac3_extract_exponents_sse2 (uint8_t *exp, int32_t *coef, int nb_coefs);
 extern void ff_ac3_extract_exponents_ssse3(uint8_t *exp, int32_t *coef, int nb_coefs);
 
-#if ARCH_X86_32 && defined(__INTEL_COMPILER)
+#if ARCH_X86_32 && (defined(__INTEL_COMPILER) || defined(__clang__))
 #       undef HAVE_7REGS
 #       define HAVE_7REGS 0
 #endif
