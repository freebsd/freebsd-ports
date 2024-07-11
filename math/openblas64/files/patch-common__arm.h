--- common_arm.h.orig	2023-04-01 20:18:01 UTC
+++ common_arm.h
@@ -95,6 +95,17 @@ static inline int blas_quickdivide(blasint x, blasint 
 
 #endif
 
+/* Translate pre-UAL asm to UAL equivalents */
+#if defined(__clang__)
+#define fnmacs vmls.f32
+#define fnmacd vmls.f64
+#define fnmuls vnmul.f32
+#define fnmuld vnmul.f64
+#define fldmias vldmia
+#define fstmias vstmia
+#define fldmiad vldmia
+#define fstmiad vstmia
+#endif
 
 #ifndef F_INTERFACE
 #define REALNAME ASMNAME
