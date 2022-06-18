--- content/zygote/zygote_main_linux.cc.orig	2022-06-17 14:20:10 UTC
+++ content/zygote/zygote_main_linux.cc
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
@@ -41,7 +43,9 @@
 #include "sandbox/linux/services/thread_helpers.h"
 #include "sandbox/linux/suid/client/setuid_sandbox_client.h"
 #include "sandbox/policy/linux/sandbox_debug_handling_linux.h"
+#if !defined(OS_BSD)
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 #include "sandbox/policy/sandbox.h"
 #include "sandbox/policy/switches.h"
 #include "third_party/icu/source/i18n/unicode/timezone.h"
@@ -50,6 +54,7 @@ namespace content {
 
 namespace {
 
+#if !defined(OS_BSD)
 void CloseFds(const std::vector<int>& fds) {
   for (const auto& it : fds) {
     PCHECK(0 == IGNORE_EINTR(close(it)));
@@ -67,9 +72,11 @@ base::OnceClosure ClosureFromTwoClosures(base::OnceClo
       },
       std::move(one), std::move(two));
 }
+#endif
 
 }  // namespace
 
+#if !defined(OS_BSD)
 // This function triggers the static and lazy construction of objects that need
 // to be created before imposing the sandbox.
 static void ZygotePreSandboxInit() {
@@ -174,9 +181,11 @@ static void EnterLayerOneSandbox(sandbox::policy::Sand
     CHECK(!using_layer1_sandbox);
   }
 }
+#endif
 
 bool ZygoteMain(
     std::vector<std::unique_ptr<ZygoteForkDelegate>> fork_delegates) {
+#if !defined(OS_BSD)
   sandbox::SetAmZygoteOrRenderer(true, GetSandboxFD());
 
   auto* linux_sandbox = sandbox::policy::SandboxLinux::GetInstance();
@@ -241,6 +250,9 @@ bool ZygoteMain(
 
   // This function call can return multiple times, once per fork().
   return zygote.ProcessRequests();
+#else
+  return false;
+#endif
 }
 
 }  // namespace content
