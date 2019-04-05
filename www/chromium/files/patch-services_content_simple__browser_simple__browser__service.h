--- services/content/simple_browser/simple_browser_service.h.orig	2019-03-11 22:01:01 UTC
+++ services/content/simple_browser/simple_browser_service.h
@@ -16,7 +16,7 @@
 #include "services/service_manager/public/cpp/service_binding.h"
 #include "services/service_manager/public/mojom/service.mojom.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"  // nogncheck
 #endif
 
@@ -50,7 +50,7 @@ class COMPONENT_EXPORT(SIMPLE_BROWSER) SimpleBrowserSe
   // service_manager::Service:
   void OnStart() override;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   sk_sp<font_service::FontLoader> font_loader_;
 #endif
 
