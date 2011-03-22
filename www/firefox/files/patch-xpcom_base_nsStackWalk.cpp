--- xpcom/base/nsStackWalk.cpp.orig	2010-12-15 02:03:41.000000000 +0100
+++ xpcom/base/nsStackWalk.cpp	2010-12-15 11:28:20.000000000 +0100
@@ -1137,7 +1137,7 @@
 #define __USE_GNU
 #endif
 
-#if defined(HAVE_DLOPEN) || defined(XP_MACOSX)
+#if defined(HAVE_DLOPEN) || defined(XP_MACOSX) || defined(__FreeBSD__)
 #include <dlfcn.h>
 #endif
 
