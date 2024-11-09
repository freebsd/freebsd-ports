--- src/fft.h.orig	2024-10-15 16:15:00 UTC
+++ src/fft.h
@@ -32,6 +32,12 @@
 //#define USE_FLOAT
 #define USE_DOUBLE
 
+#ifdef __cplusplus
+#define complex __complex__
+#undef I
+#define I ((float __complex__)1.0j)
+#endif
+
 #ifdef USE_FLOAT
 typedef float complex complex_t;
 typedef float real_t;
