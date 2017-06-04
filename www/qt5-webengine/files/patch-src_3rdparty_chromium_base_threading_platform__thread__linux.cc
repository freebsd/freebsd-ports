--- src/3rdparty/chromium/base/threading/platform_thread_linux.cc.orig	2017-04-11 14:08:45 UTC
+++ src/3rdparty/chromium/base/threading/platform_thread_linux.cc
@@ -17,7 +17,9 @@
 
 #if !defined(OS_NACL)
 #include <pthread.h>
+#if !defined(OS_BSD)
 #include <sys/prctl.h>
+#endif
 #include <sys/types.h>
 #include <unistd.h>
 #endif
@@ -81,7 +83,7 @@ void PlatformThread::SetName(const std::string& name) 
   ThreadIdNameManager::GetInstance()->SetName(CurrentId(), name);
   tracked_objects::ThreadData::InitializeThreadContext(name);
 
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
   // On linux we can get the thread names to show up in the debugger by setting
   // the process name for the LWP.  We don't want to do this for the main
   // thread because that would rename the process, causing tools like killall
