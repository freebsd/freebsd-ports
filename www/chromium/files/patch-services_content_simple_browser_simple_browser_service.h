--- services/content/simple_browser/simple_browser_service.h.orig	2019-01-09 13:09:39.690142000 +0100
+++ services/content/simple_browser/simple_browser_service.h	2019-01-09 13:10:00.488808000 +0100
@@ -14,7 +14,7 @@
 #include "services/content/public/cpp/buildflags.h"
 #include "services/service_manager/public/cpp/service.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"  // nogncheck
 #endif
 
@@ -47,7 +47,7 @@
   // service_manager::Service:
   void OnStart() override;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   sk_sp<font_service::FontLoader> font_loader_;
 #endif
 
