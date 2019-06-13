--- content/browser/service_manager/service_manager_context.cc.orig	2019-06-04 18:55:23 UTC
+++ content/browser/service_manager/service_manager_context.cc
@@ -99,7 +99,7 @@
 #include "jni/ContentNfcDelegate_jni.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/services/font/font_service_app.h"
 #include "components/services/font/public/interfaces/constants.mojom.h"
 #endif
@@ -378,12 +378,12 @@ void CreateInProcessAudioService(
                      BrowserMainLoop::GetAudioManager(), std::move(request)));
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 std::unique_ptr<service_manager::Service> CreateFontService(
     service_manager::mojom::ServiceRequest request) {
   return std::make_unique<font_service::FontServiceApp>(std::move(request));
 }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 std::unique_ptr<service_manager::Service> CreateResourceCoordinatorService(
     service_manager::mojom::ServiceRequest request) {
@@ -605,7 +605,7 @@ ServiceManagerContext::ServiceManagerContext(
         base::BindRepeating(&CreateVideoCaptureService));
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   RegisterInProcessService(
       packaged_services_connection_.get(), font_service::mojom::kServiceName,
       base::CreateSequencedTaskRunnerWithTraits(
