--- src/3rdparty/chromium/sandbox/policy/sandbox.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/sandbox/policy/sandbox.h
@@ -12,6 +12,10 @@
 #include "sandbox/policy/linux/sandbox_linux.h"
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/openbsd/sandbox_openbsd.h"
+#endif  
+
 namespace sandbox {
 namespace mojom {
 enum class Sandbox;
@@ -32,7 +36,7 @@ class SANDBOX_POLICY_EXPORT Sandbox {
 
 class SANDBOX_POLICY_EXPORT Sandbox {
  public:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static bool Initialize(sandbox::mojom::Sandbox sandbox_type,
                          SandboxLinux::PreSandboxHook hook,
                          const SandboxLinux::Options& options);
