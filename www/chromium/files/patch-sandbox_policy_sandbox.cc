--- sandbox/policy/sandbox.cc.orig	2022-02-07 13:39:41 UTC
+++ sandbox/policy/sandbox.cc
@@ -17,6 +17,10 @@
 #include "sandbox/policy/linux/sandbox_linux.h"
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
 
+#if defined(OS_BSD)
+#include "sandbox/policy/openbsd/sandbox_openbsd.h"
+#endif  // defined(OS_BSD)
+
 #if defined(OS_MAC)
 #include "sandbox/mac/seatbelt.h"
 #endif  // defined(OS_MAC)
@@ -30,7 +34,7 @@
 namespace sandbox {
 namespace policy {
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 bool Sandbox::Initialize(sandbox::mojom::Sandbox sandbox_type,
                          SandboxLinux::PreSandboxHook hook,
                          const SandboxLinux::Options& options) {
