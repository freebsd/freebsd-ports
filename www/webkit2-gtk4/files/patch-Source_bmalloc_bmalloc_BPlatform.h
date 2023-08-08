Index: Source/bmalloc/bmalloc/BPlatform.h
--- Source/bmalloc/bmalloc/BPlatform.h.orig
+++ Source/bmalloc/bmalloc/BPlatform.h
@@ -52,6 +52,10 @@
 #define BOS_FREEBSD 1
 #endif
 
+#if defined(__OpenBSD__)
+#define BOS_OPENBSD 1
+#endif
+
 #if defined(WIN32) || defined(_WIN32)
 #define BOS_WINDOWS 1
 #endif
