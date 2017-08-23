--- third_party/WebKit/Source/platform/wtf/Assertions.cpp.orig	2017-07-25 21:05:15.000000000 +0200
+++ third_party/WebKit/Source/platform/wtf/Assertions.cpp	2017-08-02 15:55:53.426469000 +0200
@@ -60,7 +60,7 @@
 #include <windows.h>
 #endif
 
-#if OS(MACOSX) || (OS(LINUX) && !defined(__UCLIBC__))
+#if OS(MACOSX) || ((OS(LINUX) || OS(BSD)) && !defined(__UCLIBC__))
 #include <cxxabi.h>
 #include <dlfcn.h>
 #include <execinfo.h>
