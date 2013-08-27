--- base/threading/platform_thread_linux.cc.orig	2013-08-17 20:52:20.000000000 +0300
+++ base/threading/platform_thread_linux.cc	2013-08-17 20:56:34.000000000 +0300
@@ -16,7 +16,9 @@
 #include "base/tracked_objects.h"
 
 #if !defined(OS_NACL)
+#if !defined(OS_BSD)
 #include <sys/prctl.h>
+#endif
 #include <sys/resource.h>
 #include <sys/syscall.h>
 #include <sys/time.h>
@@ -52,7 +54,7 @@
   ThreadIdNameManager::GetInstance()->SetName(CurrentId(), name);
   tracked_objects::ThreadData::InitializeThreadContext(name);
 
-#ifndef OS_NACL
+#if !defined(OS_NACL) && !defined(OS_BSD)
   // On linux we can get the thread names to show up in the debugger by setting
   // the process name for the LWP.  We don't want to do this for the main
   // thread because that would rename the process, causing tools like killall
