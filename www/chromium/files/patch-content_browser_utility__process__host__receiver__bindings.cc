--- content/browser/utility_process_host_receiver_bindings.cc.orig	2020-09-08 19:14:05 UTC
+++ content/browser/utility_process_host_receiver_bindings.cc
@@ -10,7 +10,7 @@
 #include "content/public/browser/content_browser_client.h"
 #include "content/public/common/content_client.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/services/font/public/mojom/font_service.mojom.h"  // nogncheck
 #include "content/browser/font_service.h"  // nogncheck
 #endif
@@ -19,7 +19,7 @@ namespace content {
 
 void UtilityProcessHost::BindHostReceiver(
     mojo::GenericPendingReceiver receiver) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (auto font_receiver = receiver.As<font_service::mojom::FontService>()) {
     ConnectToFontService(std::move(font_receiver));
     return;
