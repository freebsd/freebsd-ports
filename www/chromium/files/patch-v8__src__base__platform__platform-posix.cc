--- v8/src/base/platform/platform-posix.cc.orig	2015-01-27 03:22:59.000000000 +0100
+++ v8/src/base/platform/platform-posix.cc	2015-02-06 18:41:53.881294389 +0100
@@ -259,6 +259,14 @@
   return static_cast<int>(syscall(__NR_gettid));
 #elif V8_OS_ANDROID
   return static_cast<int>(gettid());
+#elif V8_OS_FREEBSD
+#  ifdef __DragonFly__
+  return static_cast<int>(lwp_gettid());
+#  elif __FreeBSD_version__ < 900031
+  return 0; /* ! */
+#  else
+  return static_cast<int>(pthread_getthreadid_np());
+#  endif
 #else
   return static_cast<int>(pthread_self());
 #endif
