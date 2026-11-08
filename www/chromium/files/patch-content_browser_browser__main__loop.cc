--- content/browser/browser_main_loop.cc.orig	2026-10-18 13:29:39 UTC
+++ content/browser/browser_main_loop.cc
@@ -263,6 +263,12 @@
 #include "mojo/public/cpp/bindings/lib/test_random_mojo_delays.h"
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include "content/browser/sandbox_host_linux.h"
+#include "content/public/common/zygote/sandbox_support_linux.h"
+#include "sandbox/policy/sandbox.h"
+#endif
+
 // One of the linux specific headers defines this as a macro.
 #ifdef DestroyAll
 #undef DestroyAll
@@ -542,6 +548,12 @@ int BrowserMainLoop::EarlyInitialization() {
   // before the browser main loop starts.
   CHECK(SandboxHostLinux::GetInstance()->IsInitialized(),
         base::NotFatalUntil::M159);
+#elif BUILDFLAG(IS_BSD)
+  base::FileHandleMappingVector additional_remapped_fds;
+  base::LaunchOptions options;
+  SandboxHostLinux::GetInstance()->Init();
+  const int sfd = SandboxHostLinux::GetInstance()->GetChildSocket();
+  options.fds_to_remap.push_back(std::make_pair(sfd, GetSandboxFD()));
 #endif
 
   // GLib's spawning of new processes is buggy, so it's important that at this
@@ -573,7 +585,7 @@ int BrowserMainLoop::EarlyInitialization() {
   base::PlatformThread::SetDefaultThreadType(base::ThreadType::kPresentation);
 
 #if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // We use quite a few file descriptors for our IPC as well as disk the disk
   // cache, and the default limit on Apple is low (256), so bump it up.
 
