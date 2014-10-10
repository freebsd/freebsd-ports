--- v8/src/base/platform/platform-posix.cc.orig	2014-10-02 17:41:11 UTC
+++ v8/src/base/platform/platform-posix.cc
@@ -324,7 +324,9 @@
 #if defined(ANDROID)
   return static_cast<int>(syscall(__NR_gettid));
 #else
+#ifdef HAVE_SYSCALL_H
   return static_cast<int>(syscall(SYS_gettid));
+#endif
 #endif  // defined(ANDROID)
 }
 
