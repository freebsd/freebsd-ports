--- ./base/threading/platform_thread_linux.cc.orig	2014-04-30 22:41:42.000000000 +0200
+++ ./base/threading/platform_thread_linux.cc	2014-05-04 14:38:46.000000000 +0200
@@ -16,7 +16,9 @@
 #include "base/tracked_objects.h"
 
 #if !defined(OS_NACL)
+#if !defined(OS_BSD)
 #include <sys/prctl.h>
+#endif
 #include <sys/resource.h>
 #include <sys/syscall.h>
 #include <sys/time.h>
@@ -48,7 +50,7 @@
   ThreadIdNameManager::GetInstance()->SetName(CurrentId(), name);
   tracked_objects::ThreadData::InitializeThreadContext(name);
 
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
   // On linux we can get the thread names to show up in the debugger by setting
   // the process name for the LWP.  We don't want to do this for the main
   // thread because that would rename the process, causing tools like killall
