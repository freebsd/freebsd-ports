--- v8/src/base/platform/platform-posix.cc.orig	2015-01-25 14:30:34 UTC
+++ v8/src/base/platform/platform-posix.cc
@@ -259,6 +259,8 @@
   return static_cast<int>(syscall(__NR_gettid));
 #elif V8_OS_ANDROID
   return static_cast<int>(gettid());
+#elif V8_OS_FREEBSD
+  return static_cast<int>(pthread_getthreadid_np());
 #else
   return static_cast<int>(pthread_self());
 #endif
