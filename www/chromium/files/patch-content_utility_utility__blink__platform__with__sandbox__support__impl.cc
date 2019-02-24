--- content/utility/utility_blink_platform_with_sandbox_support_impl.cc.orig	2019-02-06 23:15:41.158565000 +0100
+++ content/utility/utility_blink_platform_with_sandbox_support_impl.cc	2019-02-06 23:16:32.076308000 +0100
@@ -9,7 +9,7 @@
 #if defined(OS_MACOSX)
 #include "base/mac/foundation_util.h"
 #include "content/child/child_process_sandbox_support_impl_mac.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "base/synchronization/lock.h"
 #include "content/child/child_process_sandbox_support_impl_linux.h"
 #include "content/child/child_thread_impl.h"
@@ -26,7 +26,7 @@
 
 namespace content {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 class UtilityBlinkPlatformWithSandboxSupportImpl::SandboxSupport
     : public blink::WebSandboxSupport {
@@ -59,12 +59,12 @@
   sk_sp<font_service::FontLoader> font_loader_;
 };
 
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 UtilityBlinkPlatformWithSandboxSupportImpl::
     UtilityBlinkPlatformWithSandboxSupportImpl(
         service_manager::Connector* connector) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   font_loader_ = sk_make_sp<font_service::FontLoader>(connector);
   SkFontConfigInterface::SetGlobal(font_loader_);
   sandbox_support_ = std::make_unique<SandboxSupport>(font_loader_);
@@ -78,14 +78,14 @@
 
 blink::WebSandboxSupport*
 UtilityBlinkPlatformWithSandboxSupportImpl::GetSandboxSupport() {
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   return sandbox_support_.get();
 #else
   return nullptr;
 #endif
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 void UtilityBlinkPlatformWithSandboxSupportImpl::SandboxSupport::
     GetFallbackFontForCharacter(blink::WebUChar32 character,
