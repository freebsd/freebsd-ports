--- content/ppapi_plugin/ppapi_blink_platform_impl.h.orig	2024-06-25 12:08:48 UTC
+++ content/ppapi_plugin/ppapi_blink_platform_impl.h
@@ -34,7 +34,7 @@ class PpapiBlinkPlatformImpl : public BlinkPlatformImp
   blink::WebString DefaultLocale() override;
 
  private:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 };
