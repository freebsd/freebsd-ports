--- base/threading/platform_thread_linux.cc.orig	2015-05-13 18:35:44.000000000 -0400
+++ base/threading/platform_thread_linux.cc    2015-05-20 09:16:20.394597000 -0400
@@ -15,7 +15,9 @@
 
 #if !defined(OS_NACL)
 #include <pthread.h>
+#if !defined(OS_BSD)
 #include <sys/prctl.h>
+#endif
 #include <sys/types.h>
 #include <unistd.h>
 #endif
@@ -74,7 +76,7 @@
   ThreadIdNameManager::GetInstance()->SetName(CurrentId(), name);
   tracked_objects::ThreadData::InitializeThreadContext(name);
 
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
   // On linux we can get the thread names to show up in the debugger by setting
   // the process name for the LWP.  We don't want to do this for the main
   // thread because that would rename the process, causing tools like killall
