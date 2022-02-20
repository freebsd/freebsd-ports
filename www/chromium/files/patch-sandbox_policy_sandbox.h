--- sandbox/policy/sandbox.h.orig	2022-02-07 13:39:41 UTC
+++ sandbox/policy/sandbox.h
@@ -12,6 +12,10 @@
 #include "sandbox/policy/linux/sandbox_linux.h"
 #endif
 
+#if defined(OS_BSD)
+#include "sandbox/policy/openbsd/sandbox_openbsd.h"
+#endif  
+
 namespace sandbox {
 namespace mojom {
 enum class Sandbox;
@@ -32,7 +36,7 @@ namespace policy {
 
 class SANDBOX_POLICY_EXPORT Sandbox {
  public:
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   static bool Initialize(sandbox::mojom::Sandbox sandbox_type,
                          SandboxLinux::PreSandboxHook hook,
                          const SandboxLinux::Options& options);
