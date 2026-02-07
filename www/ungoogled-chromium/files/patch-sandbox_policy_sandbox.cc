--- sandbox/policy/sandbox.cc.orig	2025-09-10 13:22:16 UTC
+++ sandbox/policy/sandbox.cc
@@ -18,6 +18,10 @@
 #include "sandbox/policy/linux/sandbox_linux.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#endif  // BUILDFLAG(IS_BSD)
+
 #if BUILDFLAG(IS_MAC)
 #include "sandbox/mac/seatbelt.h"
 #endif  // BUILDFLAG(IS_MAC)
@@ -34,7 +38,7 @@
 namespace sandbox {
 namespace policy {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool Sandbox::Initialize(sandbox::mojom::Sandbox sandbox_type,
                          SandboxLinux::PreSandboxHook hook,
                          const SandboxLinux::Options& options) {
