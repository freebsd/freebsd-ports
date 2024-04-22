--- media/gpu/sandbox/hardware_video_decoding_sandbox_hook_linux.cc.orig	2024-04-19 13:02:56 UTC
+++ media/gpu/sandbox/hardware_video_decoding_sandbox_hook_linux.cc
@@ -16,7 +16,9 @@
 #include "media/gpu/vaapi/vaapi_wrapper.h"
 #endif
 
+#if !BUILDFLAG(IS_BSD)
 using sandbox::syscall_broker::BrokerFilePermission;
+#endif
 
 // TODO(b/195769334): the hardware video decoding sandbox is really only useful
 // when building with VA-API or V4L2 (otherwise, we're not really doing hardware
@@ -32,6 +34,7 @@ using sandbox::syscall_broker::BrokerFilePermission;
 namespace media {
 namespace {
 
+#if !BUILDFLAG(IS_BSD)
 void AllowAccessToRenderNodes(std::vector<BrokerFilePermission>& permissions,
                               bool include_sys_dev_char,
                               bool read_write) {
@@ -182,6 +185,7 @@ bool HardwareVideoDecodingPreSandboxHookForV4L2(
   NOTREACHED_NORETURN();
 #endif  // BUILDFLAG(USE_V4L2_CODEC)
 }
+#endif
 
 }  // namespace
 
@@ -197,6 +201,7 @@ bool HardwareVideoDecodingPreSandboxHookForV4L2(
 //   (at least).
 bool HardwareVideoDecodingPreSandboxHook(
     sandbox::policy::SandboxLinux::Options options) {
+#if !BUILDFLAG(IS_BSD)
   using HardwareVideoDecodingProcessPolicy =
       sandbox::policy::HardwareVideoDecodingProcessPolicy;
   using PolicyType =
@@ -242,6 +247,7 @@ bool HardwareVideoDecodingPreSandboxHook(
   // |permissions| is empty?
   sandbox::policy::SandboxLinux::GetInstance()->StartBrokerProcess(
       command_set, permissions, options);
+#endif
   return true;
 }
 
