--- api/fftw3.h.orig	2026-04-18 10:17:59 UTC
+++ api/fftw3.h
@@ -470,10 +470,12 @@ FFTW_DEFINE_API(FFTW_MANGLE_LONG_DOUBLE, long double, 
 FFTW_DEFINE_API(FFTW_MANGLE_LONG_DOUBLE, long double, fftwl_complex)
 
 /* __float128 (quad precision) is a gcc extension on i386, x86_64, and ia64
-   for gcc >= 4.6 (compiled in FFTW with --enable-quad-precision) */
+   for gcc >= 4.6, and on PowerPC when gcc defines __FLOAT128__
+   (compiled in FFTW with --enable-quad-precision) */
 #if (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)) \
  && !(defined(__ICC) || defined(__INTEL_COMPILER) || defined(__CUDACC__) || defined(__PGI)) \
- && (defined(__i386__) || defined(__x86_64__) || defined(__ia64__))
+ && (defined(__i386__) || defined(__x86_64__) || defined(__ia64__) \
+     || (defined(_ARCH_PPC) && defined(__FLOAT128__)))
 #  if !defined(FFTW_NO_Complex) && defined(_Complex_I) && defined(complex) && defined(I)
 /* note: __float128 is a typedef, which is not supported with the _Complex
          keyword in gcc, so instead we use this ugly __attribute__ version.
@@ -481,7 +483,14 @@ FFTW_DEFINE_API(FFTW_MANGLE_LONG_DOUBLE, long double, 
          FFTW_DEFINE_API because the __attribute__ confuses gcc in pointer
          types.  Hence redefining FFTW_DEFINE_COMPLEX.  Ugh. */
 #    undef FFTW_DEFINE_COMPLEX
-#    define FFTW_DEFINE_COMPLEX(R, C) typedef _Complex float __attribute__((mode(TC))) C
+#    if defined(_ARCH_PPC) && !defined(__LONG_DOUBLE_IEEE128__)
+/* PowerPC where long double is not the IEEE 128-bit type: __float128 is
+   the separate KFmode type, so its complex type is KCmode, not TCmode
+   (which is the IBM double-double long double on Linux) */
+#      define FFTW_DEFINE_COMPLEX(R, C) typedef _Complex float __attribute__((mode(KC))) C
+#    else
+#      define FFTW_DEFINE_COMPLEX(R, C) typedef _Complex float __attribute__((mode(TC))) C
+#    endif
 #  endif
 FFTW_DEFINE_API(FFTW_MANGLE_QUAD, __float128, fftwq_complex)
 #endif
