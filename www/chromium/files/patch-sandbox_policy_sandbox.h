--- sandbox/policy/sandbox.h.orig	2022-01-20 10:36:01 UTC
+++ sandbox/policy/sandbox.h
@@ -8,6 +8,10 @@
 #include "build/build_config.h"
 #include "sandbox/policy/export.h"
 
+#if defined(OS_FREEBSD)
+#include "sandbox/policy/freebsd/sandbox_freebsd.h"
+#endif
+
 #if defined(OS_LINUX) || defined(OS_CHROMEOS)
 #include "sandbox/policy/linux/sandbox_linux.h"
 #endif
@@ -32,6 +36,10 @@ namespace policy {
 
 class SANDBOX_POLICY_EXPORT Sandbox {
  public:
+#if defined(OS_FREEBSD)
+  static bool Initialize(sandbox::mojom::Sandbox sandbox_type);
+#endif  // defined(OS_FREEBSD)
+
 #if defined(OS_LINUX) || defined(OS_CHROMEOS)
   static bool Initialize(sandbox::mojom::Sandbox sandbox_type,
                          SandboxLinux::PreSandboxHook hook,
