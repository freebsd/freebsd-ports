--- src/3rdparty/chromium/sandbox/policy/sandbox.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/sandbox/policy/sandbox.h
@@ -12,6 +12,12 @@
 #include "sandbox/policy/linux/sandbox_linux.h"
 #endif
 
+#if BUILDFLAG(IS_OPENBSD)
+#include "sandbox/policy/openbsd/sandbox_openbsd.h"
+#elif BUILDFLAG(IS_FREEBSD)
+#include "sandbox/policy/freebsd/sandbox_freebsd.h"
+#endif
+
 namespace sandbox {
 namespace mojom {
 enum class Sandbox;
@@ -32,7 +38,7 @@ class SANDBOX_POLICY_EXPORT Sandbox {
 
 class SANDBOX_POLICY_EXPORT Sandbox {
  public:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static bool Initialize(sandbox::mojom::Sandbox sandbox_type,
                          SandboxLinux::PreSandboxHook hook,
                          const SandboxLinux::Options& options);
