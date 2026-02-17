--- content/browser/browser_child_process_host_impl_receiver_bindings.cc.orig	2026-02-15 10:01:45 UTC
+++ content/browser/browser_child_process_host_impl_receiver_bindings.cc
@@ -38,7 +38,7 @@
 #include "content/public/common/font_cache_win.mojom.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/services/font_data/font_data_service_impl.h"
 #endif
 
@@ -69,7 +69,7 @@ void BrowserChildProcessHostImpl::BindHostReceiver(
     }
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (auto r = receiver.As<mojom::ThreadTypeSwitcher>()) {
     child_thread_type_switcher_.Bind(std::move(r));
     return;
@@ -111,7 +111,7 @@ void BrowserChildProcessHostImpl::BindHostReceiver(
   }
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (features::IsFontDataServiceEnabled()) {
     if (auto font_data_receiver =
             receiver.As<font_data_service::mojom::FontDataService>()) {
