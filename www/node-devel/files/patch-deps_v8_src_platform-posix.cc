--- deps/v8/src/base/platform/platform-posix.cc.orig	2015-01-30 06:13:10 UTC
+++ deps/v8/src/base/platform/platform-posix.cc
@@ -328,7 +328,7 @@ int OS::GetCurrentThreadId() {
 #elif V8_OS_ANDROID
   return static_cast<int>(gettid());
 #else
-  return static_cast<int>(pthread_self());
+  return static_cast<int>(reinterpret_cast<intptr_t>(pthread_self()));
 #endif
 }
 
