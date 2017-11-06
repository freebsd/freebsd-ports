--- v8/src/globals.h.orig	2017-04-19 19:07:57 UTC
+++ v8/src/globals.h
@@ -183,7 +183,11 @@ const size_t kCodeRangeAreaAlignment = 2
 const size_t kMaximalCodeRangeSize = 512 * MB;
 const size_t kCodeRangeAreaAlignment = 64 * KB;  // OS page on PPC Linux
 #else
+#if defined(__FreeBSD__)
+const size_t kMaximalCodeRangeSize = 256 * MB;
+#else
 const size_t kMaximalCodeRangeSize = 512 * MB;
+#endif
 const size_t kCodeRangeAreaAlignment = 4 * KB;  // OS page.
 #endif
 #if V8_OS_WIN
