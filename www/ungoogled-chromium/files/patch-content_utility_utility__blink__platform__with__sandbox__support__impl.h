--- content/utility/utility_blink_platform_with_sandbox_support_impl.h.orig	2026-08-13 07:41:05 UTC
+++ content/utility/utility_blink_platform_with_sandbox_support_impl.h
@@ -38,7 +38,7 @@ class UtilityBlinkPlatformWithSandboxSupportImpl : pub
 
  private:
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 };
