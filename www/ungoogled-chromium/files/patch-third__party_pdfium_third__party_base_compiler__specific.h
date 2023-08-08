--- third_party/pdfium/third_party/base/compiler_specific.h.orig	2023-06-05 19:39:05 UTC
+++ third_party/pdfium/third_party/base/compiler_specific.h
@@ -17,7 +17,7 @@
 // Annotate a function indicating it should not be inlined.
 // Use like:
 //   NOINLINE void DoStuff() { ... }
-#if defined(__clang__) && HAS_ATTRIBUTE(noinline)
+#if defined(__clang__) && (__clang_major__ >= 15) && HAS_ATTRIBUTE(noinline)
 #define NOINLINE [[clang::noinline]]
 #elif defined(COMPILER_GCC) && HAS_ATTRIBUTE(noinline)
 #define NOINLINE __attribute__((noinline))
