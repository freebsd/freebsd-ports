--- content/browser/service_manager/service_manager_context.cc.orig	2019-02-06 19:17:17.245963000 +0100
+++ content/browser/service_manager/service_manager_context.cc	2019-02-06 19:18:30.535127000 +0100
@@ -100,7 +100,7 @@
 #include "ui/aura/env.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/services/font/font_service_app.h"
 #include "components/services/font/public/interfaces/constants.mojom.h"
 #endif
@@ -436,7 +436,7 @@
                      BrowserMainLoop::GetAudioManager(), std::move(request)));
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void CreateFontService(service_manager::mojom::ServiceRequest request) {
   // The font service owns itself here, deleting on self-termination.
   auto service =
@@ -700,7 +700,7 @@
   out_of_process_services[data_decoder::mojom::kServiceName] =
       base::BindRepeating(&base::ASCIIToUTF16, "Data Decoder Service");
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   packaged_services_connection_->AddServiceRequestHandler(
       font_service::mojom::kServiceName,
       base::BindRepeating([](service_manager::mojom::ServiceRequest request) {
