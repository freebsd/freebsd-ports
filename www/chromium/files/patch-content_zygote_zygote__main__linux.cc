--- content/zygote/zygote_main_linux.cc.orig	2026-02-11 09:05:39 UTC
+++ content/zygote/zygote_main_linux.cc
@@ -11,7 +11,9 @@
 #include <stddef.h>
 #include <stdint.h>
 #include <string.h>
+#if !BUILDFLAG(IS_BSD)
 #include <sys/prctl.h>
+#endif
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -42,7 +44,9 @@
 #include "sandbox/linux/services/thread_helpers.h"
 #include "sandbox/linux/suid/client/setuid_sandbox_client.h"
 #include "sandbox/policy/linux/sandbox_debug_handling_linux.h"
+#if !BUILDFLAG(IS_BSD)
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 #include "sandbox/policy/sandbox.h"
 #include "sandbox/policy/switches.h"
 #include "third_party/icu/source/i18n/unicode/timezone.h"
@@ -51,11 +55,13 @@ namespace content {
 
 namespace {
 
+#if !BUILDFLAG(IS_BSD)
 void CloseFds(const std::vector<int>& fds) {
   for (const auto& it : fds) {
     PCHECK(0 == IGNORE_EINTR(close(it)));
   }
 }
+#endif
 
 base::OnceClosure ClosureFromTwoClosures(base::OnceClosure one,
                                          base::OnceClosure two) {
@@ -158,9 +164,11 @@ static void EnterLayerOneSandbox(sandbox::policy::Sand
     CHECK(!using_layer1_sandbox);
   }
 }
+#endif
 
 bool ZygoteMain(
     std::vector<std::unique_ptr<ZygoteForkDelegate>> fork_delegates) {
+#if !BUILDFLAG(IS_BSD)
   sandbox::SetAmZygoteOrRenderer(true, GetSandboxFD());
 
   auto* linux_sandbox = sandbox::policy::SandboxLinux::GetInstance();
@@ -225,6 +233,9 @@ bool ZygoteMain(
 
   // This function call can return multiple times, once per fork().
   return zygote.ProcessRequests();
+#else
+  return false;
+#endif
 }
 
 }  // namespace content
