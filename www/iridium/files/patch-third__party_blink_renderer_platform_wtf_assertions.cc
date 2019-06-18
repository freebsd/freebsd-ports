--- third_party/blink/renderer/platform/wtf/assertions.cc.orig	2019-03-11 22:01:04 UTC
+++ third_party/blink/renderer/platform/wtf/assertions.cc
@@ -48,7 +48,7 @@
 #include <windows.h>
 #endif
 
-#if defined(OS_MACOSX) || (defined(OS_LINUX) && !defined(__UCLIBC__))
+#if defined(OS_MACOSX) || ((defined(OS_LINUX) || defined(OS_BSD)) && !defined(__UCLIBC__))
 #include <cxxabi.h>
 #include <dlfcn.h>
 #include <execinfo.h>
