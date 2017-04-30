--- base/threading/platform_thread_linux.cc.orig	2017-04-19 19:06:28 UTC
+++ base/threading/platform_thread_linux.cc
@@ -19,7 +19,9 @@
 
 #if !defined(OS_NACL)
 #include <pthread.h>
+#if !defined(OS_BSD)
 #include <sys/prctl.h>
+#endif
 #include <sys/resource.h>
 #include <sys/time.h>
 #include <sys/types.h>
@@ -130,7 +132,7 @@ void PlatformThread::SetName(const std::
   ThreadIdNameManager::GetInstance()->SetName(CurrentId(), name);
   tracked_objects::ThreadData::InitializeThreadContext(name);
 
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
   // On linux we can get the thread names to show up in the debugger by setting
   // the process name for the LWP.  We don't want to do this for the main
   // thread because that would rename the process, causing tools like killall
@@ -150,7 +152,7 @@ void PlatformThread::SetName(const std::
 #endif  //  !defined(OS_NACL)
 }
 
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
 // static
 void PlatformThread::SetThreadPriority(PlatformThreadId thread_id,
                                        ThreadPriority priority) {
