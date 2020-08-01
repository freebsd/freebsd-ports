--- gpu/command_buffer/tests/webgpu_test.cc.orig	2020-07-13 09:46:01 UTC
+++ gpu/command_buffer/tests/webgpu_test.cc
@@ -51,7 +51,7 @@ bool WebGPUTest::WebGPUSupported() const {
 
 bool WebGPUTest::WebGPUSharedImageSupported() const {
   // Currently WebGPUSharedImage is only implemented on Mac, Linux and Windows
-#if (defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_WIN)) && \
+#if (defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)) && \
     BUILDFLAG(USE_DAWN)
   return true;
 #else
@@ -62,7 +62,7 @@ bool WebGPUTest::WebGPUSharedImageSupported() const {
 void WebGPUTest::SetUp() {
   gpu::GpuPreferences gpu_preferences;
   gpu_preferences.enable_webgpu = true;
-#if defined(OS_LINUX) && BUILDFLAG(USE_DAWN)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && BUILDFLAG(USE_DAWN)
   gpu_preferences.use_vulkan = gpu::VulkanImplementationName::kNative;
   gpu_preferences.gr_context_type = gpu::GrContextType::kVulkan;
 #elif defined(OS_WIN)
