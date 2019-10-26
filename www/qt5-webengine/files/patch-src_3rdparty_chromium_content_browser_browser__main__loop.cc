--- src/3rdparty/chromium/content/browser/browser_main_loop.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/content/browser/browser_main_loop.cc
@@ -255,6 +255,11 @@
 #include "mojo/public/cpp/bindings/lib/test_random_mojo_delays.h"
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
@@ -634,7 +644,7 @@ int BrowserMainLoop::EarlyInitialization() {
 #endif  // defined(OS_ANDROID) || defined(OS_CHROMEOS)
 
 #if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_ANDROID)
+    defined(OS_ANDROID) || defined(OS_BSD)
   // We use quite a few file descriptors for our IPC as well as disk the disk
   // cache,and the default limit on the Mac is low (256), so bump it up.
 
@@ -644,7 +654,7 @@ int BrowserMainLoop::EarlyInitialization() {
   // an arbitrarily high number. See https://crbug.com/539567
   base::IncreaseFdLimitTo(8192);
 #endif  // defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_CHROMEOS) ||
-        // defined(OS_ANDROID)
+        // defined(OS_ANDROID) || defined(OS_BSD)
 
 #if defined(OS_WIN)
   net::EnsureWinsockInit();
