--- content/browser/utility_sandbox_delegate.cc.orig	2022-03-28 18:11:04 UTC
+++ content/browser/utility_sandbox_delegate.cc
@@ -62,7 +62,7 @@ UtilitySandboxedProcessLauncherDelegate::
 #if BUILDFLAG(ENABLE_PLUGINS)
       sandbox_type_ == sandbox::mojom::Sandbox::kPpapi ||
 #endif
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kVideoCapture ||
 #endif
 #if BUILDFLAG(IS_CHROMEOS_ASH)
