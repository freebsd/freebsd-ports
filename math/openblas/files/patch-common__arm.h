--- common_arm.h.orig	2016-09-01 03:58:42 UTC
+++ common_arm.h
@@ -93,6 +93,17 @@ static inline int blas_quickdivide(blasint x, blasint
 
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
