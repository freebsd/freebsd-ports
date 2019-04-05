--- content/utility/utility_blink_platform_with_sandbox_support_impl.cc.orig	2019-03-11 22:00:58 UTC
+++ content/utility/utility_blink_platform_with_sandbox_support_impl.cc
@@ -8,7 +8,7 @@
 
 #if defined(OS_MACOSX)
 #include "content/child/child_process_sandbox_support_impl_mac.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "content/child/child_process_sandbox_support_impl_linux.h"
 #endif
 
@@ -17,7 +17,7 @@ namespace content {
 UtilityBlinkPlatformWithSandboxSupportImpl::
     UtilityBlinkPlatformWithSandboxSupportImpl(
         service_manager::Connector* connector) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   font_loader_ = sk_make_sp<font_service::FontLoader>(connector);
   SkFontConfigInterface::SetGlobal(font_loader_);
   sandbox_support_ = std::make_unique<WebSandboxSupportLinux>(font_loader_);
@@ -31,7 +31,7 @@ UtilityBlinkPlatformWithSandboxSupportImpl::
 
 blink::WebSandboxSupport*
 UtilityBlinkPlatformWithSandboxSupportImpl::GetSandboxSupport() {
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   return sandbox_support_.get();
 #else
   return nullptr;
