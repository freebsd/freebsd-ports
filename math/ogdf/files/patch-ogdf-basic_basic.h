--- ogdf/basic/basic.h.orig	2013-06-18 10:18:02.000000000 +0200
+++ ogdf/basic/basic.h	2013-06-18 10:19:00.000000000 +0200
@@ -88,6 +88,9 @@
 #define OGDF_SYSTEM_OSX
 #endif
 
+#if defined(__FreeBSD__)
+#define OGDF_SYSTEM_FREEBSD
+#endif
 
 #if defined(USE_COIN) || defined(OGDF_OWN_LPSOLVER)
 #define OGDF_LP_SOLVER
