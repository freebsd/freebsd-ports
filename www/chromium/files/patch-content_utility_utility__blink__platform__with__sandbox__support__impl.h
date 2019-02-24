--- content/utility/utility_blink_platform_with_sandbox_support_impl.h.orig	2019-02-06 23:17:20.242437000 +0100
+++ content/utility/utility_blink_platform_with_sandbox_support_impl.h	2019-02-06 23:17:37.808893000 +0100
@@ -11,7 +11,7 @@
 #include "build/build_config.h"
 #include "third_party/blink/public/platform/platform.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"  // nogncheck
 #include "third_party/skia/include/core/SkRefCnt.h"           // nogncheck
 #endif
@@ -39,10 +39,10 @@
   blink::WebSandboxSupport* GetSandboxSupport() override;
 
  private:
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   class SandboxSupport;
   sk_sp<font_service::FontLoader> font_loader_;
 #endif
