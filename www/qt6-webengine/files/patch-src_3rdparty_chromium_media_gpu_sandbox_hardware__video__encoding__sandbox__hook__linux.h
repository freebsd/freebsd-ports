--- src/3rdparty/chromium/media/gpu/sandbox/hardware_video_encoding_sandbox_hook_linux.h.orig	2023-01-11 09:17:16 UTC
+++ src/3rdparty/chromium/media/gpu/sandbox/hardware_video_encoding_sandbox_hook_linux.h
@@ -5,7 +5,13 @@
 #ifndef MEDIA_GPU_SANDBOX_HARDWARE_VIDEO_ENCODING_SANDBOX_HOOK_LINUX_H_
 #define MEDIA_GPU_SANDBOX_HARDWARE_VIDEO_ENCODING_SANDBOX_HOOK_LINUX_H_
 
+#include "build/build_config.h"
+
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/openbsd/sandbox_openbsd.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace media {
 
@@ -14,4 +20,4 @@ bool HardwareVideoEncodingPreSandboxHook(
 
 }  // namespace media
 
-#endif  // MEDIA_GPU_SANDBOX_HARDWARE_VIDEO_ENCODING_SANDBOX_HOOK_LINUX_H_
\ No newline at end of file
+#endif  // MEDIA_GPU_SANDBOX_HARDWARE_VIDEO_ENCODING_SANDBOX_HOOK_LINUX_H_
