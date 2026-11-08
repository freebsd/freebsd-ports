--- sandbox/policy/sandbox_type.cc.orig	2026-10-18 13:29:39 UTC
+++ sandbox/policy/sandbox_type.cc
@@ -13,7 +13,7 @@
 #include "sandbox/policy/mojom/sandbox.mojom.h"
 #include "sandbox/policy/switches.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "media/gpu/buildflags.h"  // nogncheck
 #include "media/media_buildflags.h"  // nogncheck
 #endif
@@ -35,13 +35,13 @@ constexpr char kServiceSandboxWithJit[] = "service_wit
 constexpr char kSpeechRecognitionSandbox[] = "speech_recognition";
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 constexpr char kPrintBackendSandbox[] = "print_backend";
 constexpr char kScreenAISandbox[] = "screen_ai";
 constexpr char kPlatformRuntimeSandbox[] = "platform_runtime";
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // The XR Device Service hosts the OpenXR runtime; it is sandboxed on Windows
 // and Linux.
 constexpr char kXrCompositingSandbox[] = "xr_compositing";
@@ -63,11 +63,11 @@ constexpr char kProxyResolverSandbox[] = "proxy_resolv
 constexpr char kWebNNModelCompilationSandbox[] = "webnn_model_compilation";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 constexpr char kVideoCaptureSandbox[] = "video_capture";
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 constexpr char kShapeDetectionSandbox[] = "shape_detection";
 // USE_LINUX_VIDEO_ACCELERATION implies IS_LINUX || IS_CHROMEOS, so this double
 // #if is redundant, however, we cannot include "media/gpu/buildflags.h" on all
@@ -87,7 +87,7 @@ constexpr char kTtsSandbox[] = "tts";
 constexpr char kNearbySandbox[] = "nearby";
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 constexpr char kOnDeviceTranslationSandbox[] = "on_device_translation";
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
 
@@ -137,10 +137,10 @@ void SetCommandLineFlagsForSandboxType(base::CommandLi
     case Sandbox::kCdm:
     case Sandbox::kPrintCompositor:
     case Sandbox::kAudio:
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoCapture:
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case Sandbox::kXrCompositing:
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 #if BUILDFLAG(IS_WIN)
@@ -149,7 +149,7 @@ void SetCommandLineFlagsForSandboxType(base::CommandLi
     case Sandbox::kIconReader:
     case Sandbox::kMediaFoundationCdm:
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kShapeDetection:
 #if BUILDFLAG(ENABLE_OOP_VIDEO_DECODER)
     case Sandbox::kHardwareVideoDecoding:
@@ -171,13 +171,13 @@ void SetCommandLineFlagsForSandboxType(base::CommandLi
     case Sandbox::kWebNNModelCompilation:
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     case Sandbox::kPrintBackend:
     case Sandbox::kScreenAI:
     case Sandbox::kPlatformRuntime:
 #endif
     case Sandbox::kSpeechRecognition:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kOnDeviceTranslation:
 #endif
       DCHECK(command_line->GetSwitchValueASCII(switches::kProcessType) ==
@@ -187,7 +187,7 @@ void SetCommandLineFlagsForSandboxType(base::CommandLi
           switches::kServiceSandboxType,
           StringFromUtilitySandboxType(sandbox_type));
       return;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kZygoteIntermediateSandbox:
       return;
 #endif
@@ -218,7 +218,7 @@ sandbox::mojom::Sandbox SandboxTypeFromCommandLine(
     return Sandbox::kGpu;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Intermediate process gains a sandbox later.
   if (process_type == switches::kZygoteProcessType)
     return Sandbox::kZygoteIntermediateSandbox;
@@ -260,7 +260,7 @@ std::string StringFromUtilitySandboxType(Sandbox sandb
       return kUtilitySandbox;
     case Sandbox::kAudio:
       return kAudioSandbox;
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoCapture:
       return kVideoCaptureSandbox;
 #endif
@@ -271,7 +271,7 @@ std::string StringFromUtilitySandboxType(Sandbox sandb
     case Sandbox::kSpeechRecognition:
       return kSpeechRecognitionSandbox;
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     case Sandbox::kPrintBackend:
       return kPrintBackendSandbox;
     case Sandbox::kScreenAI:
@@ -279,11 +279,11 @@ std::string StringFromUtilitySandboxType(Sandbox sandb
     case Sandbox::kPlatformRuntime:
       return kPlatformRuntimeSandbox;
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kOnDeviceTranslation:
       return kOnDeviceTranslationSandbox;
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case Sandbox::kXrCompositing:
       return kXrCompositingSandbox;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
@@ -305,7 +305,7 @@ std::string StringFromUtilitySandboxType(Sandbox sandb
     case Sandbox::kWebNNModelCompilation:
       return kWebNNModelCompilationSandbox;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kShapeDetection:
       return kShapeDetectionSandbox;
 #if BUILDFLAG(ENABLE_OOP_VIDEO_DECODER)
@@ -328,7 +328,7 @@ std::string StringFromUtilitySandboxType(Sandbox sandb
       // The following are not utility processes so should not occur.
     case Sandbox::kRenderer:
     case Sandbox::kGpu:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kZygoteIntermediateSandbox:
 #endif
       NOTREACHED();
@@ -373,7 +373,7 @@ sandbox::mojom::Sandbox UtilitySandboxTypeFromString(
   if (sandbox_string == kPrintCompositorSandbox) {
     return Sandbox::kPrintCompositor;
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (sandbox_string == kXrCompositingSandbox) {
     return Sandbox::kXrCompositing;
   }
@@ -409,7 +409,7 @@ sandbox::mojom::Sandbox UtilitySandboxTypeFromString(
     return Sandbox::kSpeechRecognition;
   }
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (sandbox_string == kPrintBackendSandbox) {
     return Sandbox::kPrintBackend;
   }
@@ -420,17 +420,17 @@ sandbox::mojom::Sandbox UtilitySandboxTypeFromString(
     return Sandbox::kPlatformRuntime;
   }
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (sandbox_string == kOnDeviceTranslationSandbox) {
     return Sandbox::kOnDeviceTranslation;
   }
 #endif
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   if (sandbox_string == kVideoCaptureSandbox) {
     return Sandbox::kVideoCapture;
   }
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (sandbox_string == kShapeDetectionSandbox) {
     return Sandbox::kShapeDetection;
   }
