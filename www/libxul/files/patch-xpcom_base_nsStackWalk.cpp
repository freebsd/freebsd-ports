--- xpcom/base/nsStackWalk.cpp.orig	2010-01-11 02:11:49.000000000 -0500
+++ xpcom/base/nsStackWalk.cpp	2010-01-11 02:13:26.000000000 -0500
@@ -1132,7 +1132,7 @@
 #define __USE_GNU
 #endif
 
-#if defined(HAVE_LIBDL) || defined(XP_MACOSX)
+#if defined(HAVE_LIBDL) || defined(XP_MACOSX) || defined(__FreeBSD__)
 #include <dlfcn.h>
 #endif
 
