--- ffmpeg/libavcodec/x86/ac3dsp_init.c	2013-07-03 21:34:20.000000000 +0200
+++ ffmpeg/libavcodec/x86/ac3dsp_init.c	2013-07-03 21:34:45.000000000 +0200
@@ -51,7 +51,7 @@
 extern void ff_ac3_extract_exponents_sse2 (uint8_t *exp, int32_t *coef, int nb_coefs);
 extern void ff_ac3_extract_exponents_ssse3(uint8_t *exp, int32_t *coef, int nb_coefs);
 
-#if ARCH_X86_32 && defined(__INTEL_COMPILER)
+#if ARCH_X86_32 && (defined(__INTEL_COMPILER) || defined(__clang__))
 #       undef HAVE_7REGS
 #       define HAVE_7REGS 0
 #endif
