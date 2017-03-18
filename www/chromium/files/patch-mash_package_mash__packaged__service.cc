--- mash/package/mash_packaged_service.cc.orig	2017-03-09 20:04:34 UTC
+++ mash/package/mash_packaged_service.cc
@@ -29,7 +29,7 @@
 #include "ash/touch_hud/mus/touch_hud_application.h"  // nogncheck
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/font_service/font_service_app.h"
 #endif
 
@@ -103,7 +103,7 @@ std::unique_ptr<service_manager::Service
     return base::WrapUnique(new mash::task_viewer::TaskViewer);
   if (name == "test_ime_driver")
     return base::WrapUnique(new ui::test::TestIMEApplication);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (name == "font_service")
     return base::WrapUnique(new font_service::FontServiceApp);
 #endif
