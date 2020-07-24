--- components/viz/common/gpu/dawn_context_provider.cc.orig	2020-02-26 13:14:08 UTC
+++ components/viz/common/gpu/dawn_context_provider.cc
@@ -17,7 +17,7 @@ namespace {
 dawn_native::BackendType GetDefaultBackendType() {
 #if defined(OS_WIN)
   return dawn_native::BackendType::D3D12;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return dawn_native::BackendType::Vulkan;
 #else
   NOTREACHED();
