--- src/lib/geogram/basic/atomics.h.orig	2018-12-09 17:41:31 UTC
+++ src/lib/geogram/basic/atomics.h
@@ -54,7 +54,7 @@
  * \brief Functions for atomic operations
  */
 
-#ifdef GEO_OS_LINUX
+#if defined(GEO_OS_LINUX) || defined(GEO_OS_FREEBSD)
 #  if defined(GEO_OS_EMSCRIPTEN) 
 #    define GEO_USE_DUMMY_ATOMICS
 #  elif defined(GEO_OS_RASPBERRY)
