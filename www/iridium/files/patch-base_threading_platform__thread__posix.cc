--- base/threading/platform_thread_posix.cc.orig	2019-03-11 22:00:51 UTC
+++ base/threading/platform_thread_posix.cc
@@ -66,7 +66,7 @@ void* ThreadFunc(void* params) {
     if (!thread_params->joinable)
       base::ThreadRestrictions::SetSingletonAllowed(false);
 
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
     // Threads on linux/android may inherit their priority from the thread
     // where they were created. This explicitly sets the priority of all new
     // threads.
