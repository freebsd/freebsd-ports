--- xpcom/base/nsStackWalk.cpp.orig	2010-12-15 02:03:41.000000000 +0100
+++ xpcom/base/nsStackWalk.cpp	2010-12-15 11:28:20.000000000 +0100
@@ -1137,7 +1137,7 @@
 #define __USE_GNU
 #endif
 
-#if defined(HAVE_DLOPEN) || defined(XP_MACOSX)
+#if defined(HAVE_DLOPEN) || defined(XP_MACOSX) || defined(__FreeBSD__)
 #include <dlfcn.h>
 #endif
 
@@ -1123,6 +1123,7 @@ NS_StackWalk(NS_WalkStackCallback aCallb
 
 #elif defined(HAVE__UNWIND_BACKTRACE)
 
+#define _GNU_SOURCE
 // libgcc_s.so symbols _Unwind_Backtrace@@GCC_3.3 and _Unwind_GetIP@@GCC_3.0
 #include <unwind.h>
 
