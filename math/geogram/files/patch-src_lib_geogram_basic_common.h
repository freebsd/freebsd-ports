--- src/lib/geogram/basic/common.h.orig	2018-12-09 17:36:40 UTC
+++ src/lib/geogram/basic/common.h
@@ -221,6 +221,35 @@ namespace GEO {
 #  define GEO_ARCH_32
 #endif
 
+// =============================== FreeBSD defines =========================
+
+#elif defined(__FreeBSD__)
+
+#define GEO_OS_FREEBSD
+#define GEO_OS_UNIX
+
+#if defined(_OPENMP)
+#  define GEO_OPENMP
+#endif
+
+#if defined(__INTEL_COMPILER)
+#  define GEO_COMPILER_INTEL
+#elif defined(__clang__)
+#  define GEO_COMPILER_CLANG
+#elif defined(__GNUC__)
+#  define GEO_COMPILER_GCC
+#else
+#  error "Unsupported compiler"
+#endif
+
+// The following works on GCC and ICC
+#if defined(__x86_64)
+#  define GEO_ARCH_64
+#else
+#  define GEO_ARCH_32
+#endif
+
+
 // =============================== WINDOWS defines =========================
 
 #elif defined(_WIN32) || defined(_WIN64)
