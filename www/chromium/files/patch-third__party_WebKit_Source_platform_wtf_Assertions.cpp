--- third_party/WebKit/Source/platform/wtf/Assertions.cpp.orig	2017-09-05 21:05:41.000000000 +0200
+++ third_party/WebKit/Source/platform/wtf/Assertions.cpp	2017-09-06 22:08:33.610705000 +0200
@@ -56,7 +56,7 @@
 #include <windows.h>
 #endif
 
-#if defined(OS_MACOSX) || (defined(OS_LINUX) && !defined(__UCLIBC__))
+#if defined(OS_MACOSX) || ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(__UCLIBC__))
 #include <cxxabi.h>
 #include <dlfcn.h>
 #include <execinfo.h>
