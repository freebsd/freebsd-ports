--- services/audio/audio_sandbox_hook_linux.h.orig	2023-04-28 17:01:32 UTC
+++ services/audio/audio_sandbox_hook_linux.h
@@ -5,7 +5,11 @@
 #ifndef SERVICES_AUDIO_AUDIO_SANDBOX_HOOK_LINUX_H_
 #define SERVICES_AUDIO_AUDIO_SANDBOX_HOOK_LINUX_H_
 
+#if defined(OS_BSD)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace audio {
 
