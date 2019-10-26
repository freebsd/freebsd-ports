--- src/3rdparty/chromium/content/ppapi_plugin/ppapi_blink_platform_impl.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/content/ppapi_plugin/ppapi_blink_platform_impl.h
@@ -13,7 +13,7 @@
 #include "build/build_config.h"
 #include "content/child/blink_platform_impl.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"
 #include "third_party/skia/include/core/SkRefCnt.h"
 #endif
@@ -42,11 +42,11 @@ class PpapiBlinkPlatformImpl : public BlinkPlatformImp
                          bool sync_dir) override;
 
  private:
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   sk_sp<font_service::FontLoader> font_loader_;
 #endif
 
