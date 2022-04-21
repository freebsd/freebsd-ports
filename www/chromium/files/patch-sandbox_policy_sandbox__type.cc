--- sandbox/policy/sandbox_type.cc.orig	2022-04-21 18:48:31 UTC
+++ sandbox/policy/sandbox_type.cc
@@ -39,7 +39,7 @@ bool IsUnsandboxedSandboxType(Sandbox sandbox_type) {
 #endif
     case Sandbox::kAudio:
       return false;
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoCapture:
       return false;
 #endif
@@ -70,8 +70,10 @@ bool IsUnsandboxedSandboxType(Sandbox sandbox_type) {
     case Sandbox::kLibassistant:
 #endif  // BUILDFLAG(ENABLE_CROS_LIBASSISTANT)
 #endif  // // BUILDFLAG(IS_CHROMEOS_ASH)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
+#if !BUILDFLAG(IS_BSD)
     case Sandbox::kZygoteIntermediateSandbox:
+#endif
     case Sandbox::kScreenAI:
 #endif
     case Sandbox::kSpeechRecognition:
@@ -123,7 +125,7 @@ void SetCommandLineFlagsForSandboxType(base::CommandLi
 #endif
     case Sandbox::kPrintCompositor:
     case Sandbox::kAudio:
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoCapture:
 #endif
 #if BUILDFLAG(IS_WIN)
@@ -145,7 +147,7 @@ void SetCommandLineFlagsForSandboxType(base::CommandLi
 #if BUILDFLAG(IS_MAC)
     case Sandbox::kMirroring:
 #endif  // BUILDFLAG(IS_MAC)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kScreenAI:
 #endif
     case Sandbox::kSpeechRecognition:
@@ -251,7 +253,7 @@ std::string StringFromUtilitySandboxType(Sandbox sandb
       return switches::kUtilitySandbox;
     case Sandbox::kAudio:
       return switches::kAudioSandbox;
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     case Sandbox::kVideoCapture:
       return switches::kVideoCaptureSandbox;
 #endif
@@ -261,7 +263,7 @@ std::string StringFromUtilitySandboxType(Sandbox sandb
       return switches::kServiceSandboxWithJit;
     case Sandbox::kSpeechRecognition:
       return switches::kSpeechRecognitionSandbox;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     case Sandbox::kScreenAI:
       return switches::kScreenAISandbox;
 #endif
@@ -363,11 +365,11 @@ sandbox::mojom::Sandbox UtilitySandboxTypeFromString(
     return Sandbox::kAudio;
   if (sandbox_string == switches::kSpeechRecognitionSandbox)
     return Sandbox::kSpeechRecognition;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (sandbox_string == switches::kScreenAISandbox)
     return Sandbox::kScreenAI;
 #endif
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   if (sandbox_string == switches::kVideoCaptureSandbox)
     return Sandbox::kVideoCapture;
 #endif
