--- src/3rdparty/chromium/v8/src/globals.h.orig	2017-12-15 19:22:04.283569000 -0500
+++ src/3rdparty/chromium/v8/src/globals.h	2017-12-15 19:23:21.959960000 -0500
@@ -179,7 +179,11 @@
 const size_t kMaximalCodeRangeSize = 256 * MB;
 const size_t kCodeRangeAreaAlignment = 256 * MB;
 #elif V8_HOST_ARCH_PPC && V8_TARGET_ARCH_PPC && V8_OS_LINUX
+#if defined(__FreeBSD__)
+const size_t kMaximalCodeRangeSize = 256 * MB;
+#else
 const size_t kMaximalCodeRangeSize = 512 * MB;
+#endif
 const size_t kCodeRangeAreaAlignment = 64 * KB;  // OS page on PPC Linux
 #else
 const size_t kMaximalCodeRangeSize = 512 * MB;
