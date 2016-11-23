--- third_party/WebKit/Source/wtf/Assertions.cpp.orig	2016-07-20 22:03:42.000000000 +0300
+++ third_party/WebKit/Source/wtf/Assertions.cpp	2016-08-12 11:13:22.515917000 +0300
@@ -59,7 +59,7 @@
 #include <windows.h>
 #endif

-#if OS(MACOSX) || (OS(LINUX) && !defined(__UCLIBC__))
+#if OS(MACOSX) || ((OS(LINUX) || OS(BSD)) && !defined(__UCLIBC__))
 #include <cxxabi.h>
 #include <dlfcn.h>
 #include <execinfo.h>
@@ -159,7 +159,7 @@

 void WTFGetBacktrace(void** stack, int* size)
 {
-#if OS(MACOSX) || (OS(LINUX) && !defined(__UCLIBC__))
+#if OS(MACOSX) || ((OS(LINUX) || OS(BSD)) && !defined(__UCLIBC__))
     *size = backtrace(stack, *size);
 #elif OS(WIN)
     // The CaptureStackBackTrace function is available in XP, but it is not defined
@@ -210,7 +210,7 @@
     : m_name(0)
     , m_cxaDemangled(0)
 {
-#if OS(MACOSX) || (OS(LINUX) && !defined(__UCLIBC__))
+#if OS(MACOSX) || ((OS(LINUX) || OS(BSD)) && !defined(__UCLIBC__))
     Dl_info info;
     if (!dladdr(addr, &info) || !info.dli_sname)
         return;
