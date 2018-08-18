--- v8/src/globals.h.orig	2018-08-16 12:05:52.848951000 +0200
+++ v8/src/globals.h	2018-08-16 12:07:04.615399000 +0200
@@ -196,7 +196,11 @@
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
