--- v8/src/base/platform/platform-posix.cc.orig	2018-02-24 16:26:18.000000000 +0100
+++ v8/src/base/platform/platform-posix.cc	2018-03-04 05:02:38.985674000 +0100
@@ -459,6 +459,12 @@
   return static_cast<int>(syscall(__NR_gettid));
 #elif V8_OS_ANDROID
   return static_cast<int>(gettid());
+#elif V8_OS_DRAGONFLYBSD || defined(__DragonFly__)
+  return static_cast<int>(lwp_gettid());
+#elif V8_OS_FREEBSD
+  return static_cast<int>(pthread_getthreadid_np());
+#elif V8_OS_NETBSD
+  return static_cast<int>(_lwp_self());
 #elif V8_OS_AIX
   return static_cast<int>(thread_self());
 #elif V8_OS_FUCHSIA
