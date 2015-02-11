--- ./deps/v8/src/base/platform/platform-posix.cc.orig	2015-02-07 04:04:23.000000000 +0800
+++ ./deps/v8/src/base/platform/platform-posix.cc	2015-02-08 01:11:42.000000000 +0800
@@ -328,7 +328,7 @@
 #elif V8_OS_ANDROID
   return static_cast<int>(gettid());
 #else
-  return static_cast<int>(pthread_self());
+  return static_cast<int>(reinterpret_cast<intptr_t>(pthread_self()));
 #endif
 }
 
