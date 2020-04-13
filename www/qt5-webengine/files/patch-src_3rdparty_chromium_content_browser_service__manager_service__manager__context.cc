--- src/3rdparty/chromium/content/browser/service_manager/service_manager_context.cc.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/content/browser/service_manager/service_manager_context.cc
@@ -98,7 +98,7 @@
 #include "content/public/android/content_jni_headers/ContentNfcDelegate_jni.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/services/font/font_service_app.h"
 #include "components/services/font/public/mojom/constants.mojom.h"  // nogncheck
 #endif
@@ -341,12 +341,12 @@ void CreateInProcessAudioService(
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
@@ -657,7 +657,7 @@ ServiceManagerContext::ServiceManagerContext(
         base::BindRepeating(&CreateVideoCaptureService));
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   RegisterInProcessService(
       font_service::mojom::kServiceName,
       base::CreateSequencedTaskRunnerWithTraits(
