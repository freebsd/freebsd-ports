--- content/utility/speech/speech_recognition_sandbox_hook_linux.h.orig	2026-11-11 14:44:17 UTC
+++ content/utility/speech/speech_recognition_sandbox_hook_linux.h
@@ -5,8 +5,15 @@
 #ifndef CONTENT_UTILITY_SPEECH_SPEECH_RECOGNITION_SANDBOX_HOOK_LINUX_H_
 #define CONTENT_UTILITY_SPEECH_SPEECH_RECOGNITION_SANDBOX_HOOK_LINUX_H_
 
+#include "build/build_config.h"
+
 #include "base/files/file_path.h"
+
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace speech {
 
