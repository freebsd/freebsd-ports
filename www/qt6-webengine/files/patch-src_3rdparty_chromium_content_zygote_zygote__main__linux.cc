--- src/3rdparty/chromium/content/zygote/zygote_main_linux.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/content/zygote/zygote_main_linux.cc
@@ -11,7 +11,9 @@
 #include <stddef.h>
 #include <stdint.h>
 #include <string.h>
+#if !defined(OS_BSD)
 #include <sys/prctl.h>
+#endif
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -40,7 +42,9 @@
 #include "sandbox/linux/services/thread_helpers.h"
 #include "sandbox/linux/suid/client/setuid_sandbox_client.h"
 #include "sandbox/policy/linux/sandbox_debug_handling_linux.h"
+#if !defined(OS_BSD)
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 #include "sandbox/policy/sandbox.h"
 #include "sandbox/policy/switches.h"
 #include "third_party/icu/source/i18n/unicode/timezone.h"
@@ -49,6 +53,7 @@ namespace {
 
 namespace {
 
+#if !defined(OS_BSD)
 void CloseFds(const std::vector<int>& fds) {
   for (const auto& it : fds) {
     PCHECK(0 == IGNORE_EINTR(close(it)));
@@ -66,9 +71,11 @@ base::OnceClosure ClosureFromTwoClosures(base::OnceClo
       },
       std::move(one), std::move(two));
 }
+#endif
 
 }  // namespace
 
+#if !defined(OS_BSD)
 // This function triggers the static and lazy construction of objects that need
 // to be created before imposing the sandbox.
 static void ZygotePreSandboxInit() {
@@ -175,9 +182,11 @@ static void EnterLayerOneSandbox(sandbox::policy::Sand
     CHECK(!using_layer1_sandbox);
   }
 }
+#endif
 
 bool ZygoteMain(
     std::vector<std::unique_ptr<ZygoteForkDelegate>> fork_delegates) {
+#if !defined(OS_BSD)
   sandbox::SetAmZygoteOrRenderer(true, GetSandboxFD());
 
   auto* linux_sandbox = sandbox::policy::SandboxLinux::GetInstance();
@@ -243,6 +252,9 @@ bool ZygoteMain(
 
   // This function call can return multiple times, once per fork().
   return zygote.ProcessRequests();
+#else
+  return false;
+#endif
 }
 
 }  // namespace content
