--- components/viz/common/gpu/dawn_context_provider.cc.orig	2021-04-14 18:41:02 UTC
+++ components/viz/common/gpu/dawn_context_provider.cc
@@ -20,7 +20,7 @@ namespace {
 dawn_native::BackendType GetDefaultBackendType() {
 #if defined(OS_WIN)
   return dawn_native::BackendType::D3D12;
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return dawn_native::BackendType::Vulkan;
 #else
   NOTREACHED();
