--- src/3rdparty/chromium/content/utility/utility_blink_platform_with_sandbox_support_impl.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/content/utility/utility_blink_platform_with_sandbox_support_impl.cc
@@ -9,7 +9,7 @@
 
 #if BUILDFLAG(IS_MAC)
 #include "content/child/child_process_sandbox_support_impl_mac.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/child/child_process_sandbox_support_impl_linux.h"
 #endif
 
@@ -17,7 +17,7 @@ UtilityBlinkPlatformWithSandboxSupportImpl::
 
 UtilityBlinkPlatformWithSandboxSupportImpl::
     UtilityBlinkPlatformWithSandboxSupportImpl() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   mojo::PendingRemote<font_service::mojom::FontService> font_service;
   UtilityThread::Get()->BindHostReceiver(
       font_service.InitWithNewPipeAndPassReceiver());
@@ -34,7 +34,7 @@ UtilityBlinkPlatformWithSandboxSupportImpl::GetSandbox
 
 blink::WebSandboxSupport*
 UtilityBlinkPlatformWithSandboxSupportImpl::GetSandboxSupport() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return sandbox_support_.get();
 #else
   return nullptr;
