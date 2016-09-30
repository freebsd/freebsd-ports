--- deps/v8/src/base/platform/platform-posix.cc.orig	2016-09-27 17:30:02 UTC
+++ deps/v8/src/base/platform/platform-posix.cc
@@ -327,7 +327,7 @@ int OS::GetCurrentThreadId() {
 #elif V8_OS_ANDROID
   return static_cast<int>(gettid());
 #else
-  return static_cast<int>(pthread_self());
+  return static_cast<int>(reinterpret_cast<intptr_t>(pthread_self()));
 #endif
 }
 
