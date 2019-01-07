--- content/ppapi_plugin/ppapi_blink_platform_impl.h.orig	2018-12-29 00:40:09.590096000 +0100
+++ content/ppapi_plugin/ppapi_blink_platform_impl.h	2018-12-29 00:41:23.439801000 +0100
@@ -13,7 +13,7 @@
 #include "build/build_config.h"
 #include "content/child/blink_platform_impl.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"
 #include "third_party/skia/include/core/SkRefCnt.h"
 #endif
@@ -47,7 +47,7 @@
   std::unique_ptr<SandboxSupport> sandbox_support_;
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   sk_sp<font_service::FontLoader> font_loader_;
 #endif
 
