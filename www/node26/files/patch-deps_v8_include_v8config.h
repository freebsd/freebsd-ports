--- deps/v8/include/v8config.h.orig	2025-07-15 17:11:17 UTC
+++ deps/v8/include/v8config.h
@@ -976,7 +976,7 @@ V8 shared library set USING_V8_SHARED.
 #define V8_TARGET_LITTLE_ENDIAN 1
 #endif
 #elif V8_TARGET_ARCH_PPC64
-#if V8_OS_AIX
+#if defined(__BIG_ENDIAN__) || defined(V8_OS_AIX)
 #define V8_TARGET_BIG_ENDIAN 1
 #else
 #define V8_TARGET_LITTLE_ENDIAN 1
