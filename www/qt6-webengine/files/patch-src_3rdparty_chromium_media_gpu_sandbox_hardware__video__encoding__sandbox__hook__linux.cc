--- src/3rdparty/chromium/media/gpu/sandbox/hardware_video_encoding_sandbox_hook_linux.cc.orig	2023-01-11 09:17:16 UTC
+++ src/3rdparty/chromium/media/gpu/sandbox/hardware_video_encoding_sandbox_hook_linux.cc
@@ -18,12 +18,15 @@
 #include "media/gpu/v4l2/v4l2_device.h"
 #endif
 
+#if !BUILDFLAG(IS_BSD)
 using sandbox::syscall_broker::BrokerFilePermission;
+#endif
 
 namespace media {
 
 bool HardwareVideoEncodingPreSandboxHook(
     sandbox::policy::SandboxLinux::Options options) {
+#if !BUILDFLAG(IS_BSD)
   sandbox::syscall_broker::BrokerCommandSet command_set;
   std::vector<BrokerFilePermission> permissions;
 
@@ -125,8 +128,8 @@ bool HardwareVideoEncodingPreSandboxHook(
 #endif  // defined(__aarch64__)
   }
 #endif
-
+#endif
   return true;
 }
 
-}  // namespace media
\ No newline at end of file
+}  // namespace media
