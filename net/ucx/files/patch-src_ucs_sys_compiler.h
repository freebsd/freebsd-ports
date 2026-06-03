--- src/ucs/sys/compiler.h.orig	2026-02-04 09:52:46 UTC
+++ src/ucs/sys/compiler.h
@@ -32,7 +32,13 @@
 
 /* A function which should not be optimized */
 #if defined(HAVE_ATTRIBUTE_NOOPTIMIZE) && (HAVE_ATTRIBUTE_NOOPTIMIZE == 1)
-#define UCS_F_NOOPTIMIZE __attribute__((optimize("O0")))
+#if defined(__clang__)
+#  define UCS_F_NOOPTIMIZE __attribute__((optnone))
+#elif defined(__GNUC__)
+#  define UCS_F_NOOPTIMIZE __attribute__((optimize("O0")))
+#else
+#  define UCS_F_NOOPTIMIZE
+#endif
 #else
 #define UCS_F_NOOPTIMIZE
 #endif
