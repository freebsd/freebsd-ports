--- third_party/WebKit/Source/wtf/Assertions.cpp.orig	2016-12-13 00:15:09 UTC
+++ third_party/WebKit/Source/wtf/Assertions.cpp
@@ -60,7 +60,7 @@
 #include <windows.h>
 #endif
 
-#if OS(MACOSX) || (OS(LINUX) && !defined(__UCLIBC__))
+#if OS(MACOSX) || ((OS(LINUX) || OS(BSD)) && !defined(__UCLIBC__))
 #include <cxxabi.h>
 #include <dlfcn.h>
 #include <execinfo.h>
@@ -164,7 +164,7 @@ void WTFReportAssertionFailure(const cha
 }
 
 void WTFGetBacktrace(void** stack, int* size) {
-#if OS(MACOSX) || (OS(LINUX) && !defined(__UCLIBC__))
+#if OS(MACOSX) || ((OS(LINUX) || OS(BSD)) && !defined(__UCLIBC__))
   *size = backtrace(stack, *size);
 #elif OS(WIN)
   // The CaptureStackBackTrace function is available in XP, but it is not
@@ -215,7 +215,7 @@ class FrameToNameScope {
 };
 
 FrameToNameScope::FrameToNameScope(void* addr) : m_name(0), m_cxaDemangled(0) {
-#if OS(MACOSX) || (OS(LINUX) && !defined(__UCLIBC__))
+#if OS(MACOSX) || ((OS(LINUX) || OS(BSD)) && !defined(__UCLIBC__))
   Dl_info info;
   if (!dladdr(addr, &info) || !info.dli_sname)
     return;
