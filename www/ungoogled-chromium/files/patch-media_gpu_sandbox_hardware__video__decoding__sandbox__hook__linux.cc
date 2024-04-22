--- media/gpu/sandbox/hardware_video_decoding_sandbox_hook_linux.cc.orig	2024-03-22 14:16:19 UTC
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
@@ -166,6 +169,7 @@ bool HardwareVideoDecodingPreSandboxHookForV4L2(
   NOTREACHED_NORETURN();
 #endif  // BUILDFLAG(USE_V4L2_CODEC)
 }
+#endif
 
 }  // namespace
 
@@ -181,6 +185,7 @@ bool HardwareVideoDecodingPreSandboxHookForV4L2(
 //   (at least).
 bool HardwareVideoDecodingPreSandboxHook(
     sandbox::policy::SandboxLinux::Options options) {
+#if !BUILDFLAG(IS_BSD)
   using HardwareVideoDecodingProcessPolicy =
       sandbox::policy::HardwareVideoDecodingProcessPolicy;
   using PolicyType =
@@ -227,6 +232,7 @@ bool HardwareVideoDecodingPreSandboxHook(
   sandbox::policy::SandboxLinux::GetInstance()->StartBrokerProcess(
       command_set, permissions, sandbox::policy::SandboxLinux::PreSandboxHook(),
       options);
+#endif
   return true;
 }
 
