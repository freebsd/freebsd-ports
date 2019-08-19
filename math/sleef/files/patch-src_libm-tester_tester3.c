--- src/libm-tester/tester3.c.orig	2019-07-26 21:42:15 UTC
+++ src/libm-tester/tester3.c
@@ -71,9 +71,9 @@ static INLINE float getsvfloat32_t(svfloat32_t v, int 
 #endif
 
 #ifdef __VSX__
-static INLINE vector_double setvector_double(double d, int r) { double a[2]; memrand(a, sizeof(a)); a[r & 1] = d; return (vector double) ( a[0], a[1] ); }
+static INLINE vector_double setvector_double(double d, int r) { double a[2]; memrand(a, sizeof(a)); a[r & 1] = d; return (vector double) { a[0], a[1] }; }
 static INLINE double getvector_double(vector double v, int r) { double a[2]; return unifyValue(v[r & 1]); }
-static INLINE vector_float setvector_float(float d, int r) { float a[4]; memrand(a, sizeof(a)); a[r & 3] = d; return (vector float) ( a[0], a[1], a[2], a[3] ); }
+static INLINE vector_float setvector_float(float d, int r) { float a[4]; memrand(a, sizeof(a)); a[r & 3] = d; return (vector float) { a[0], a[1], a[2], a[3] }; }
 static INLINE float getvector_float(vector float v, int r) { float a[4]; return unifyValuef(v[r & 3]); }
 #endif
 
