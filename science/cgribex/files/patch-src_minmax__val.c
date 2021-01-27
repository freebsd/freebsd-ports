--- src/minmax_val.c.orig	2021-01-26 13:07:53 UTC
+++ src/minmax_val.c
@@ -292,6 +291,19 @@ void sse2_minmax_val_double(const double *restrict buf
 #endif // SIMD
 
 #if defined(_ARCH_PWR6)
+
+#ifndef __fsel
+static __inline__ double __fsel(double x, double y, double z)
+  __attribute__((always_inline));
+static __inline__ double
+__fsel(double x, double y, double z)
+{
+  double r;
+  __asm__("fsel %0,%1,%2,%3" : "=d"(r) : "d"(x),"d"(y),"d"(z));
+  return r;
+}
+#endif
+
 static
 void pwr6_minmax_val_double_unrolled6(const double *restrict data, size_t datasize, double *fmin, double *fmax)
 {
