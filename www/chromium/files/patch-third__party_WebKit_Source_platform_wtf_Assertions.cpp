--- third_party/WebKit/Source/platform/wtf/Assertions.cpp.orig	2017-06-05 19:03:26 UTC
+++ third_party/WebKit/Source/platform/wtf/Assertions.cpp
@@ -60,7 +60,7 @@
 #include <windows.h>
 #endif
 
-#if OS(MACOSX) || (OS(LINUX) && !defined(__UCLIBC__))
+#if OS(MACOSX) || ((OS(LINUX) || OS(BSD)) && !defined(__UCLIBC__))
 #include <cxxabi.h>
 #include <dlfcn.h>
 #include <execinfo.h>
@@ -142,7 +142,7 @@ class FrameToNameScope {
 };
 
 FrameToNameScope::FrameToNameScope(void* addr) : m_name(0), m_cxaDemangled(0) {
-#if OS(MACOSX) || (OS(LINUX) && !defined(__UCLIBC__))
+#if OS(MACOSX) || ((OS(LINUX) || OS(BSD)) && !defined(__UCLIBC__))
   Dl_info info;
   if (!dladdr(addr, &info) || !info.dli_sname)
     return;
