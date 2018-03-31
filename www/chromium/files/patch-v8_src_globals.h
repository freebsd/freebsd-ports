--- v8/src/globals.h.orig	2018-03-20 23:06:56.000000000 +0100
+++ v8/src/globals.h	2018-03-24 19:21:33.728280000 +0100
@@ -195,7 +195,11 @@
 constexpr size_t kMaximalCodeRangeSize = 512 * MB;
 constexpr size_t kCodeRangeAreaAlignment = 64 * KB;  // OS page on PPC Linux
 #else
+#if defined(__FreeBSD__)
 constexpr size_t kMaximalCodeRangeSize = 512 * MB;
+#else
+constexpr size_t kMaximalCodeRangeSize = 512 * MB;
+#endif
 constexpr size_t kCodeRangeAreaAlignment = 4 * KB;  // OS page.
 #endif
 #if V8_OS_WIN
