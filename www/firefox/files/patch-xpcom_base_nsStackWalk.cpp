--- xpcom/base/nsStackWalk.cpp.orig	2012-05-29 00:57:31.000000000 +0200
+++ xpcom/base/nsStackWalk.cpp	2012-06-03 12:33:40.000000000 +0200
@@ -57,7 +57,7 @@
 };
 static CriticalAddress gCriticalAddress;
 
-#if defined(HAVE_DLOPEN) || defined(XP_MACOSX)
+#if defined(HAVE_DLOPEN) || defined(XP_MACOSX) || defined(__FreeBSD__)
 #include <dlfcn.h>
 #endif
 
@@ -1123,6 +1123,7 @@ NS_StackWalk(NS_WalkStackCallback aCallb
 
 #elif defined(HAVE__UNWIND_BACKTRACE)
 
+#define _GNU_SOURCE
 // libgcc_s.so symbols _Unwind_Backtrace@@GCC_3.3 and _Unwind_GetIP@@GCC_3.0
 #include <unwind.h>
 
