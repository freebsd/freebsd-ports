--- third_party/blink/renderer/platform/wtf/assertions.cc.orig	2018-07-19 20:11:56.254657000 +0200
+++ third_party/blink/renderer/platform/wtf/assertions.cc	2018-07-19 20:13:24.142405000 +0200
@@ -48,7 +48,7 @@
 #include <windows.h>
 #endif
 
-#if defined(OS_MACOSX) || (defined(OS_LINUX) && !defined(__UCLIBC__))
+#if defined(OS_MACOSX) || ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(__UCLIBC__))
 #include <cxxabi.h>
 #include <dlfcn.h>
 #include <execinfo.h>
