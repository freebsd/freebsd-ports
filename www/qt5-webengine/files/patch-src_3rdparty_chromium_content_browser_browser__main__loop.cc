--- src/3rdparty/chromium/content/browser/browser_main_loop.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/content/browser/browser_main_loop.cc
@@ -241,6 +241,11 @@
 #include "base/mac/foundation_util.h"
 #endif
 
+#include "content/browser/sandbox_host_linux.h"
+#include "services/service_manager/zygote/common/common_sandbox_support_linux.h"
+#include "content/public/common/common_sandbox_support_linux.h"
+#include "services/service_manager/sandbox/sandbox.h"
+
 // One of the linux specific headers defines this as a macro.
 #ifdef DestroyAll
 #undef DestroyAll
@@ -590,6 +595,11 @@ int BrowserMainLoop::EarlyInitialization() {
   // by now since a thread to start the ServiceManager has been created
   // before the browser main loop starts.
   DCHECK(SandboxHostLinux::GetInstance()->IsInitialized());
+#elif defined(OS_BSD)
+  SandboxHostLinux::GetInstance()->Init();
+  base::FileHandleMappingVector fds_to_map;
+  const int sfd = SandboxHostLinux::GetInstance()->GetChildSocket();
+  fds_to_map.push_back(std::make_pair(sfd, service_manager::GetSandboxFD()));
 #endif
 
 #if defined(USE_X11) && !defined(TOOLKIT_QT)
