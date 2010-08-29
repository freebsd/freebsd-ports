--- xpcom/base/nsStackWalk.cpp.orig     2010-01-11 23:06:47.000000000 -0500
+++ xpcom/base/nsStackWalk.cpp  2010-01-11 23:07:29.000000000 -0500
@@ -1124,7 +1124,7 @@
 #define __USE_GNU
 #endif
 
-#if defined(HAVE_LIBDL) || defined(XP_MACOSX)
+#if defined(HAVE_LIBDL) || defined(XP_MACOSX) || defined(__FreeBSD__)
 #include <dlfcn.h>
 #endif
 
