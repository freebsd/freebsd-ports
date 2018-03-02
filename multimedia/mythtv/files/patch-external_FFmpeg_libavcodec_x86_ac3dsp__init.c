--- external/FFmpeg/libavcodec/x86/ac3dsp_init.c.orig	2015-06-16 16:03:30 UTC
+++ external/FFmpeg/libavcodec/x86/ac3dsp_init.c
@@ -51,7 +51,7 @@ extern void ff_ac3_extract_exponents_3dnow(uint8_t *ex
 extern void ff_ac3_extract_exponents_sse2 (uint8_t *exp, int32_t *coef, int nb_coefs);
 extern void ff_ac3_extract_exponents_ssse3(uint8_t *exp, int32_t *coef, int nb_coefs);
 
-#if ARCH_X86_32 && defined(__INTEL_COMPILER)
+#if ARCH_X86_32 && (defined(__INTEL_COMPILER) || defined(__clang__))
 #       undef HAVE_7REGS
 #       define HAVE_7REGS 0
 #endif
