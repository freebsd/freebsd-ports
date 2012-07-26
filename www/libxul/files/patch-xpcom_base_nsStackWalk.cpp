--- xpcom/base/nsStackWalk.cpp.orig	2010-01-11 02:11:49.000000000 -0500
+++ xpcom/base/nsStackWalk.cpp	2010-01-11 02:13:26.000000000 -0500
@@ -1132,7 +1132,7 @@
 #define __USE_GNU
 #endif
 
-#if defined(HAVE_LIBDL) || defined(XP_MACOSX)
+#if defined(HAVE_LIBDL) || defined(XP_MACOSX) || defined(__FreeBSD__)
 #include <dlfcn.h>
 #endif
 
@@ -1123,6 +1123,7 @@ NS_StackWalk(NS_WalkStackCallback aCallb
 
 #elif defined(HAVE__UNWIND_BACKTRACE)
 
+#define _GNU_SOURCE
 // libgcc_s.so symbols _Unwind_Backtrace@@GCC_3.3 and _Unwind_GetIP@@GCC_3.0
 #include <unwind.h>
 
