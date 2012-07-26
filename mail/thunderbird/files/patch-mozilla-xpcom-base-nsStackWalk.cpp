--- mozilla/xpcom/base/nsStackWalk.cpp.orig	2010-09-12 19:34:04.012503905 +0300
+++ mozilla/xpcom/base/nsStackWalk.cpp	2010-09-12 19:34:41.294462134 +0300
@@ -41,6 +41,7 @@
 /* API for getting a stack trace of the C/C++ stack on the current thread */
 
 #include "nsStackWalk.h"
+#include <dlfcn.h>
 
 #if defined(_WIN32) && (defined(_M_IX86) || defined(_M_AMD64) || defined(_M_IA64)) && !defined(WINCE) // WIN32 x86 stack walking code
 
@@ -1123,6 +1123,7 @@ NS_StackWalk(NS_WalkStackCallback aCallb
 
 #elif defined(HAVE__UNWIND_BACKTRACE)
 
+#define _GNU_SOURCE
 // libgcc_s.so symbols _Unwind_Backtrace@@GCC_3.3 and _Unwind_GetIP@@GCC_3.0
 #include <unwind.h>
 
