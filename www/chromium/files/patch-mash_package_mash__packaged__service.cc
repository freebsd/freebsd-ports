--- mash/package/mash_packaged_service.cc.orig	2017-02-02 02:02:55 UTC
+++ mash/package/mash_packaged_service.cc
@@ -19,7 +19,7 @@
 #include "services/ui/public/interfaces/constants.mojom.h"
 #include "services/ui/service.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/font_service/font_service_app.h"
 #endif
 
@@ -91,7 +91,7 @@ std::unique_ptr<service_manager::Service
     return base::WrapUnique(new mash::task_viewer::TaskViewer);
   if (name == "test_ime_driver")
     return base::WrapUnique(new ui::test::TestIMEApplication);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (name == "font_service")
     return base::WrapUnique(new font_service::FontServiceApp);
 #endif
