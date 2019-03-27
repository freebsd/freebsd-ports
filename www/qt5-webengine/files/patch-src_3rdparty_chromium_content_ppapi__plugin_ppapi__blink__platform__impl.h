--- src/3rdparty/chromium/content/ppapi_plugin/ppapi_blink_platform_impl.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/content/ppapi_plugin/ppapi_blink_platform_impl.h
@@ -13,7 +13,7 @@
 #include "build/build_config.h"
 #include "content/child/blink_platform_impl.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"
 #include "third_party/skia/include/core/SkRefCnt.h"
 #endif
@@ -58,7 +58,7 @@ class PpapiBlinkPlatformImpl : public BlinkPlatformImp
   std::unique_ptr<SandboxSupport> sandbox_support_;
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   sk_sp<font_service::FontLoader> font_loader_;
 #endif
 
