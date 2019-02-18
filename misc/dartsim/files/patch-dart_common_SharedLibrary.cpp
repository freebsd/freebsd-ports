--- dart/common/SharedLibrary.cpp.orig	2018-11-20 05:47:58 UTC
+++ dart/common/SharedLibrary.cpp
@@ -35,7 +35,7 @@
 #include "dart/common/Console.hpp"
 #include "dart/common/detail/SharedLibraryManager.hpp"
 
-#if DART_OS_LINUX || DART_OS_MACOS
+#if DART_OS_LINUX || DART_OS_FREEBSD || DART_OS_MACOS
 
 #include <dlfcn.h>
 #define DYNLIB_LOAD(a) dlopen(a, RTLD_LAZY | RTLD_GLOBAL)
@@ -123,7 +123,7 @@ void* SharedLibrary::getSymbol(const std
 //==============================================================================
 std::string SharedLibrary::getLastError() const
 {
-#if DART_OS_LINUX || DART_OS_MACOS
+#if DART_OS_LINUX || DART_OS_FREEBSD || DART_OS_MACOS
   return std::string(dlerror());
 #elif DART_OS_WINDOWS
   LPTSTR lpMsgBuf;
