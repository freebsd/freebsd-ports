--- chrome/app/mash/embedded_services.cc.orig	2017-08-01 23:40:39.943252000 +0200
+++ chrome/app/mash/embedded_services.cc	2017-08-01 23:42:02.268143000 +0200
@@ -24,9 +24,9 @@
 #include "ash/touch_hud/mus/touch_hud_application.h"  // nogncheck
 #endif                                                // defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX) && !defined(OS_ANDROID)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_ANDROID)
 #include "components/font_service/font_service_app.h"
-#endif  // defined(OS_LINUX) && !defined(OS_ANDROID)
+#endif  // (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_ANDROID)
 
 std::unique_ptr<service_manager::Service> CreateEmbeddedMashService(
     const std::string& service_name) {
@@ -53,10 +53,10 @@
     return base::MakeUnique<mash::task_viewer::TaskViewer>();
   if (service_name == "test_ime_driver")
     return base::MakeUnique<ui::test::TestIMEApplication>();
-#if defined(OS_LINUX) && !defined(OS_ANDROID)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_ANDROID)
   if (service_name == "font_service")
     return base::MakeUnique<font_service::FontServiceApp>();
-#endif  // defined(OS_LINUX) && !defined(OS_ANDROID)
+#endif  // (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_ANDROID)
 
   return nullptr;
 }
