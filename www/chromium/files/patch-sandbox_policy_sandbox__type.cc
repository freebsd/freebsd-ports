--- sandbox/policy/sandbox_type.cc.orig	2022-02-07 13:39:41 UTC
+++ sandbox/policy/sandbox_type.cc
@@ -39,7 +39,7 @@ bool IsUnsandboxedSandboxType(Sandbox sandbox_type) {
 #endif
     case Sandbox::kAudio:
       return false;
-#if defined(OS_FUCHSIA)
+#if defined(OS_FUCHSIA) || defined(OS_BSD)
     case Sandbox::kVideoCapture:
       return false;
 #endif
@@ -120,7 +120,7 @@ void SetCommandLineFlagsForSandboxType(base::CommandLi
 #endif
     case Sandbox::kPrintCompositor:
     case Sandbox::kAudio:
-#if defined(OS_FUCHSIA)
+#if defined(OS_FUCHSIA) || defined(OS_BSD)
     case Sandbox::kVideoCapture:
 #endif
 #if defined(OS_WIN)
@@ -248,7 +248,7 @@ std::string StringFromUtilitySandboxType(Sandbox sandb
       return switches::kUtilitySandbox;
     case Sandbox::kAudio:
       return switches::kAudioSandbox;
-#if defined(OS_FUCHSIA)
+#if defined(OS_FUCHSIA) || defined(OS_BSD)
     case Sandbox::kVideoCapture:
       return switches::kVideoCaptureSandbox;
 #endif
@@ -352,7 +352,7 @@ sandbox::mojom::Sandbox UtilitySandboxTypeFromString(
     return Sandbox::kAudio;
   if (sandbox_string == switches::kSpeechRecognitionSandbox)
     return Sandbox::kSpeechRecognition;
-#if defined(OS_FUCHSIA)
+#if defined(OS_FUCHSIA) || defined(OS_BSD)
   if (sandbox_string == switches::kVideoCaptureSandbox)
     return Sandbox::kVideoCapture;
 #endif
