--- content/ppapi_plugin/ppapi_blink_platform_impl.cc.orig	2019-03-11 22:00:58 UTC
+++ content/ppapi_plugin/ppapi_blink_platform_impl.cc
@@ -20,7 +20,7 @@
 
 #if defined(OS_MACOSX)
 #include "content/child/child_process_sandbox_support_impl_mac.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "content/child/child_process_sandbox_support_impl_linux.h"
 #endif
 
@@ -34,7 +34,7 @@ typedef struct CGFont* CGFontRef;
 namespace content {
 
 PpapiBlinkPlatformImpl::PpapiBlinkPlatformImpl() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   font_loader_ =
       sk_make_sp<font_service::FontLoader>(ChildThread::Get()->GetConnector());
   SkFontConfigInterface::SetGlobal(font_loader_);
@@ -49,7 +49,7 @@ PpapiBlinkPlatformImpl::~PpapiBlinkPlatformImpl() {
 }
 
 void PpapiBlinkPlatformImpl::Shutdown() {
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   // SandboxSupport contains a map of OutOfProcessFont objects, which hold
   // WebStrings and WebVectors, which become invalidated when blink is shut
   // down. Hence, we need to clear that map now, just before blink::shutdown()
@@ -59,7 +59,7 @@ void PpapiBlinkPlatformImpl::Shutdown() {
 }
 
 blink::WebSandboxSupport* PpapiBlinkPlatformImpl::GetSandboxSupport() {
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   return sandbox_support_.get();
 #else
   return nullptr;
