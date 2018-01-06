--- src/3rdparty/chromium/base/threading/platform_thread_posix.cc.orig	2017-01-26 00:49:07 UTC
+++ src/3rdparty/chromium/base/threading/platform_thread_posix.cc
@@ -56,7 +56,7 @@ void* ThreadFunc(void* params) {
     if (!thread_params->joinable)
       base::ThreadRestrictions::SetSingletonAllowed(false);
 
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
     // Threads on linux/android may inherit their priority from the thread
     // where they were created. This explicitly sets the priority of all new
     // threads.
