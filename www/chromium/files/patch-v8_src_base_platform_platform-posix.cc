--- v8/src/base/platform/platform-posix.cc.orig	2019-03-21 01:39:38.000000000 +0100
+++ v8/src/base/platform/platform-posix.cc	2019-03-24 19:04:25.066535000 +0100
@@ -376,7 +376,7 @@
 
 // static
 bool OS::HasLazyCommits() {
-#if V8_OS_AIX || V8_OS_LINUX || V8_OS_MACOSX
+#if V8_OS_AIX || V8_OS_LINUX || V8_OS_MACOSX || V8_OS_FREEBSD
   return true;
 #else
   // TODO(bbudge) Return true for all POSIX platforms.
@@ -501,6 +501,12 @@
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
