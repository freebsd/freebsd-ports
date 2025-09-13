--- sandbox/policy/sandbox_type.cc.orig	2025-09-11 13:19:19 UTC
+++ sandbox/policy/sandbox_type.cc
@@ -16,7 +16,7 @@
 #include "chromeos/ash/components/assistant/buildflags.h"
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "media/gpu/buildflags.h"  // nogncheck
 #include "media/media_buildflags.h"  // nogncheck
 #endif
@@ -38,7 +38,7 @@ constexpr char kServiceSandboxWithJit[] = "service_wit
 constexpr char kSpeechRecognitionSandbox[] = "speech_recognition";
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 constexpr char kPrintBackendSandbox[] = "print_backend";
 constexpr char kScreenAISandbox[] = "screen_ai";
 #endif
@@ -56,15 +56,15 @@ constexpr char kWindowsSystemProxyResolverSandbox[] = 
 constexpr char kMirroringSandbox[] = "mirroring";
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kVideoEffectsSandbox[] = "video_effects";
 #endif
 
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 constexpr char kVideoCaptureSandbox[] = "video_capture";
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 constexpr char kShapeDetectionSandbox[] = "shape_detection";
 // USE_LINUX_VIDEO_ACCELERATION implies IS_LINUX || IS_CHROMEOS, so this double
 // #if is redundant, however, we cannot include "media/gpu/buildflags.h" on all
@@ -85,7 +85,7 @@ constexpr char kLibassistantSandbox[] = "libassistant"
 #endif  // BUILDFLAG(ENABLE_CROS_LIBASSISTANT)
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 constexpr char kOnDeviceTranslationSandbox[] = "on_device_translation";
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
 
@@ -135,7 +135,7 @@ void SetCommandLineFlagsForSandboxType(base::CommandLi
     case Sandbox::kCdm:
     case Sandbox::kPrintCompositor:
     case Sandbox::kAudio:
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoCapture:
 #endif
 #if BUILDFLAG(IS_WIN)
@@ -146,7 +146,7 @@ void SetCommandLineFlagsForSandboxType(base::CommandLi
     case Sandbox::kMediaFoundationCdm:
     case Sandbox::kWindowsSystemProxyResolver:
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kShapeDetection:
 #if BUILDFLAG(USE_LINUX_VIDEO_ACCELERATION)
     case Sandbox::kHardwareVideoDecoding:
@@ -165,15 +165,15 @@ void SetCommandLineFlagsForSandboxType(base::CommandLi
     case Sandbox::kMirroring:
 #endif  // BUILDFLAG(IS_MAC)
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     case Sandbox::kPrintBackend:
     case Sandbox::kScreenAI:
 #endif
     case Sandbox::kSpeechRecognition:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoEffects:
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     case Sandbox::kOnDeviceTranslation:
 #endif
       DCHECK(command_line->GetSwitchValueASCII(switches::kProcessType) ==
@@ -183,7 +183,7 @@ void SetCommandLineFlagsForSandboxType(base::CommandLi
           switches::kServiceSandboxType,
           StringFromUtilitySandboxType(sandbox_type));
       return;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kZygoteIntermediateSandbox:
       return;
 #endif
@@ -214,7 +214,7 @@ sandbox::mojom::Sandbox SandboxTypeFromCommandLine(
     return Sandbox::kGpu;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Intermediate process gains a sandbox later.
   if (process_type == switches::kZygoteProcessType)
     return Sandbox::kZygoteIntermediateSandbox;
@@ -252,7 +252,7 @@ std::string StringFromUtilitySandboxType(Sandbox sandb
       return kUtilitySandbox;
     case Sandbox::kAudio:
       return kAudioSandbox;
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoCapture:
       return kVideoCaptureSandbox;
 #endif
@@ -263,17 +263,17 @@ std::string StringFromUtilitySandboxType(Sandbox sandb
     case Sandbox::kSpeechRecognition:
       return kSpeechRecognitionSandbox;
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     case Sandbox::kPrintBackend:
       return kPrintBackendSandbox;
     case Sandbox::kScreenAI:
       return kScreenAISandbox;
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoEffects:
       return kVideoEffectsSandbox;
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     case Sandbox::kOnDeviceTranslation:
       return kOnDeviceTranslationSandbox;
 #endif
@@ -293,7 +293,7 @@ std::string StringFromUtilitySandboxType(Sandbox sandb
     case Sandbox::kMirroring:
       return kMirroringSandbox;
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kShapeDetection:
       return kShapeDetectionSandbox;
 #if BUILDFLAG(ALLOW_OOP_VIDEO_DECODER)
@@ -394,7 +394,7 @@ sandbox::mojom::Sandbox UtilitySandboxTypeFromString(
     return Sandbox::kSpeechRecognition;
   }
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (sandbox_string == kPrintBackendSandbox) {
     return Sandbox::kPrintBackend;
   }
@@ -402,22 +402,22 @@ sandbox::mojom::Sandbox UtilitySandboxTypeFromString(
     return Sandbox::kScreenAI;
   }
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (sandbox_string == kVideoEffectsSandbox) {
     return Sandbox::kVideoEffects;
   }
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
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
