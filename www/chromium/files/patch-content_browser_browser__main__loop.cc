--- content/browser/browser_main_loop.cc.orig	2018-06-13 00:10:16.000000000 +0200
+++ content/browser/browser_main_loop.cc	2018-07-19 00:30:26.119970000 +0200
@@ -205,7 +205,7 @@
 #include "base/fuchsia/default_job.h"
 #endif  // defined(OS_FUCHSIA)
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #include "content/browser/sandbox_host_linux.h"
 #endif
 
@@ -240,6 +240,11 @@
 #include "services/ui/common/image_cursors_set.h"
 #endif
 
+#if defined(OS_BSD)
+#include "content/browser/sandbox_host_linux.h"
+#include "content/public/common/common_sandbox_support_linux.h"
+#endif
+
 // One of the linux specific headers defines this as a macro.
 #ifdef DestroyAll
 #undef DestroyAll
@@ -548,6 +553,11 @@
   // by now since a thread to start the ServiceManager has been created
   // before the browser main loop starts.
   DCHECK(SandboxHostLinux::GetInstance()->IsInitialized());
+#elif defined(OS_BSD)
+  SandboxHostLinux::GetInstance()->Init();
+  base::FileHandleMappingVector fds_to_map;
+  const int sfd = SandboxHostLinux::GetInstance()->GetChildSocket();
+  fds_to_map.push_back(std::make_pair(sfd, GetSandboxFD()));
 #endif
 
 #if defined(USE_X11)
