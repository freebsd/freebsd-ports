--- content/ppapi_plugin/ppapi_blink_platform_impl.cc.orig	2020-02-03 21:52:46 UTC
+++ content/ppapi_plugin/ppapi_blink_platform_impl.cc
@@ -19,7 +19,7 @@
 
 #if defined(OS_MACOSX)
 #include "content/child/child_process_sandbox_support_impl_mac.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "content/child/child_process_sandbox_support_impl_linux.h"
 #include "mojo/public/cpp/bindings/pending_remote.h"
 #endif
@@ -34,7 +34,7 @@ typedef struct CGFont* CGFontRef;
 namespace content {
 
 PpapiBlinkPlatformImpl::PpapiBlinkPlatformImpl() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   mojo::PendingRemote<font_service::mojom::FontService> font_service;
   ChildThread::Get()->BindHostReceiver(
       font_service.InitWithNewPipeAndPassReceiver());
@@ -52,7 +52,7 @@ PpapiBlinkPlatformImpl::~PpapiBlinkPlatformImpl() {
 void PpapiBlinkPlatformImpl::Shutdown() {}
 
 blink::WebSandboxSupport* PpapiBlinkPlatformImpl::GetSandboxSupport() {
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   return sandbox_support_.get();
 #else
   return nullptr;
