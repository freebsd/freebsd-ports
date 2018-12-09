--- src/lib/geogram/NL/nl_private.h.orig	2018-12-09 21:38:58 UTC
+++ src/lib/geogram/NL/nl_private.h
@@ -67,7 +67,7 @@
 #define NL_OS_APPLE
 #endif
 
-#if defined(__linux__) || defined(__ANDROID__) || defined(NL_OS_APPLE)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__ANDROID__) || defined(NL_OS_APPLE)
 /**
  * \brief Defined if compiled on a Unix-like platform.
  */
