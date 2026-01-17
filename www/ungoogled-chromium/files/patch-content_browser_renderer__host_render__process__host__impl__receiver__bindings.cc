--- content/browser/renderer_host/render_process_host_impl_receiver_bindings.cc.orig	2026-01-16 13:40:34 UTC
+++ content/browser/renderer_host/render_process_host_impl_receiver_bindings.cc
@@ -52,7 +52,7 @@
 #include "third_party/blink/public/mojom/android_font_lookup/android_font_lookup.mojom.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/services/font/public/mojom/font_service.mojom.h"  // nogncheck
 #include "content/browser/font_service.h"  // nogncheck
 #endif
@@ -74,7 +74,7 @@
 #include "content/public/common/font_cache_win.mojom.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/services/font_data/font_data_service_impl.h"
 #endif
 
@@ -340,7 +340,7 @@ void RenderProcessHostImpl::IOThreadHostImpl::BindHost
     }
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (features::IsFontDataServiceEnabled()) {
     if (auto font_data_receiver =
             receiver.As<font_data_service::mojom::FontDataService>()) {
@@ -351,7 +351,7 @@ void RenderProcessHostImpl::IOThreadHostImpl::BindHost
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (auto font_receiver = receiver.As<font_service::mojom::FontService>()) {
     ConnectToFontService(std::move(font_receiver));
     return;
@@ -379,7 +379,7 @@ void RenderProcessHostImpl::IOThreadHostImpl::BindHost
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (auto r = receiver.As<mojom::ThreadTypeSwitcher>()) {
     child_thread_type_switcher_.Bind(std::move(r));
     return;
