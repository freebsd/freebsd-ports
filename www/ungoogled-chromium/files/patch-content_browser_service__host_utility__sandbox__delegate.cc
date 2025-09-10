--- content/browser/service_host/utility_sandbox_delegate.cc.orig	2025-09-10 13:22:16 UTC
+++ content/browser/service_host/utility_sandbox_delegate.cc
@@ -28,7 +28,7 @@
 #include "chromeos/ash/components/assistant/buildflags.h"
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "media/gpu/buildflags.h"
 #include "media/media_buildflags.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -79,7 +79,7 @@ UtilitySandboxedProcessLauncherDelegate::
 #if BUILDFLAG(IS_FUCHSIA)
       sandbox_type_ == sandbox::mojom::Sandbox::kVideoCapture ||
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kShapeDetection ||
 #if BUILDFLAG(ALLOW_OOP_VIDEO_DECODER)
       sandbox_type_ == sandbox::mojom::Sandbox::kHardwareVideoDecoding ||
@@ -97,14 +97,14 @@ UtilitySandboxedProcessLauncherDelegate::
 #endif  // BUILDFLAG(ENABLE_CROS_LIBASSISTANT)
 #endif  // BUILDFLAG(IS_CHROMEOS)
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kScreenAI ||
       sandbox_type_ == sandbox::mojom::Sandbox::kPrintBackend ||
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kVideoEffects ||
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kOnDeviceTranslation ||
 #endif
       sandbox_type_ == sandbox::mojom::Sandbox::kAudio ||
@@ -164,15 +164,15 @@ ZygoteCommunication* UtilitySandboxedProcessLauncherDe
 #endif  // BUILDFLAG(ENABLE_CROS_LIBASSISTANT)
 #endif  // BUILDFLAG(IS_CHROMEOS)
       sandbox_type_ == sandbox::mojom::Sandbox::kAudio ||
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kShapeDetection ||
 #endif
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kPrintBackend ||
       sandbox_type_ == sandbox::mojom::Sandbox::kScreenAI ||
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kVideoEffects ||
       sandbox_type_ == sandbox::mojom::Sandbox::kOnDeviceTranslation ||
 #endif  // BUILDFLAG(IS_LINUX)
