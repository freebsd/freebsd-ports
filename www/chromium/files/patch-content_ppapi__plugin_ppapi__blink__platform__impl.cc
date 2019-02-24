--- content/ppapi_plugin/ppapi_blink_platform_impl.cc.orig	2019-01-30 02:17:59.000000000 +0100
+++ content/ppapi_plugin/ppapi_blink_platform_impl.cc	2019-02-01 00:41:49.296005000 +0100
@@ -36,7 +36,7 @@
 
 namespace content {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 class PpapiBlinkPlatformImpl::SandboxSupport : public WebSandboxSupport {
  public:
@@ -118,7 +118,7 @@
 #endif
 
 PpapiBlinkPlatformImpl::PpapiBlinkPlatformImpl() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   font_loader_ =
       sk_make_sp<font_service::FontLoader>(ChildThread::Get()->GetConnector());
   SkFontConfigInterface::SetGlobal(font_loader_);
@@ -134,7 +134,7 @@
 }
 
 void PpapiBlinkPlatformImpl::Shutdown() {
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   // SandboxSupport contains a map of OutOfProcessFont objects, which hold
   // WebStrings and WebVectors, which become invalidated when blink is shut
   // down. Hence, we need to clear that map now, just before blink::shutdown()
@@ -144,7 +144,7 @@
 }
 
 blink::WebSandboxSupport* PpapiBlinkPlatformImpl::GetSandboxSupport() {
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   return sandbox_support_.get();
 #else
   return nullptr;
