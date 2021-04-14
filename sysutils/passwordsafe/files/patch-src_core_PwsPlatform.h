--- src/core/PwsPlatform.h.orig	2020-10-28 19:48:24 UTC
+++ src/core/PwsPlatform.h
@@ -116,8 +116,10 @@
 // * FreeBSD on Intel                           *
 // **********************************************
 #elif defined(__FreeBSD) || defined(__FreeBSD__)
-#if defined(__i386__) || defined(__amd64__)
+#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
 #define PWS_LITTLE_ENDIAN
+#else
+#define PWS_BIG_ENDIAN
 #endif
 // **********************************************
 // * Add other platforms here...                *
