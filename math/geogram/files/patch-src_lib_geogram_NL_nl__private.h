--- src/lib/geogram/NL/nl_private.h.orig	2024-06-14 05:04:18 UTC
+++ src/lib/geogram/NL/nl_private.h
@@ -62,7 +62,7 @@
 #define NL_OS_APPLE
 #endif
 
-#if defined(__linux__) || defined(__ANDROID__) || defined(NL_OS_APPLE)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__ANDROID__) || defined(NL_OS_APPLE)
 /**
  * \brief Defined if compiled on a Unix-like platform.
  */
