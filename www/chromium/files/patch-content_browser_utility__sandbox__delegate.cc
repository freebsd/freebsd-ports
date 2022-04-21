--- content/browser/utility_sandbox_delegate.cc.orig	2022-04-21 18:48:31 UTC
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
@@ -73,7 +73,7 @@ UtilitySandboxedProcessLauncherDelegate::
       sandbox_type_ == sandbox::mojom::Sandbox::kLibassistant ||
 #endif  // BUILDFLAG(ENABLE_CROS_LIBASSISTANT)
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kScreenAI ||
 #endif
       sandbox_type_ == sandbox::mojom::Sandbox::kAudio ||
@@ -118,7 +118,7 @@ ZygoteHandle UtilitySandboxedProcessLauncherDelegate::
 #if BUILDFLAG(ENABLE_OOP_PRINTING)
       sandbox_type_ == sandbox::mojom::Sandbox::kPrintBackend ||
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kScreenAI ||
 #endif
       sandbox_type_ == sandbox::mojom::Sandbox::kSpeechRecognition) {
