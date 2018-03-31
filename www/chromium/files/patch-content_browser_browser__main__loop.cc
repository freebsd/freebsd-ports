--- content/browser/browser_main_loop.cc.orig	2018-03-20 23:05:23.000000000 +0100
+++ content/browser/browser_main_loop.cc	2018-03-24 14:03:10.531359000 +0100
@@ -212,7 +212,7 @@
 #include "base/fuchsia/default_job.h"
 #endif  // defined(OS_FUCHSIA)
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #include "content/browser/sandbox_host_linux.h"
 #include "content/browser/zygote_host/zygote_host_impl_linux.h"
 
@@ -254,6 +254,11 @@
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
@@ -655,10 +660,15 @@
   TRACE_EVENT0("startup", "BrowserMainLoop::EarlyInitialization");
 
 #if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && \
-    !defined(OS_FUCHSIA)
+    !defined(OS_FUCHSIA) && !defined(OS_BSD)
   // No thread should be created before this call, as SetupSandbox()
   // will end-up using fork().
   SetupSandbox(parsed_command_line_);
+#elif defined(OS_BSD)
+  SandboxHostLinux::GetInstance()->Init();
+  base::FileHandleMappingVector fds_to_map;
+  const int sfd = SandboxHostLinux::GetInstance()->GetChildSocket();
+  fds_to_map.push_back(std::make_pair(sfd, GetSandboxFD()));
 #endif
 
 #if defined(USE_X11)
