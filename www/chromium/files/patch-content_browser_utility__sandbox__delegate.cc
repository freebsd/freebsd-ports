--- content/browser/utility_sandbox_delegate.cc.orig	2022-02-07 13:39:41 UTC
+++ content/browser/utility_sandbox_delegate.cc
@@ -61,7 +61,7 @@ UtilitySandboxedProcessLauncherDelegate::
 #if BUILDFLAG(ENABLE_PLUGINS)
       sandbox_type_ == sandbox::mojom::Sandbox::kPpapi ||
 #endif
-#if defined(OS_FUCHSIA)
+#if defined(OS_FUCHSIA) || defined(OS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kVideoCapture ||
 #endif
 #if BUILDFLAG(IS_CHROMEOS_ASH)
