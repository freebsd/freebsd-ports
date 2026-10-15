--- cef/libcef/browser/osr/host_display_client_osr.cc.orig	2026-09-06 17:31:54 UTC
+++ cef/libcef/browser/osr/host_display_client_osr.cc
@@ -140,7 +140,7 @@ void CefHostDisplayClientOSR::CreateLaye
   layered_window_updater_->SetActive(active_);
 }
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(SUPPORTS_OZONE_X11)
 void CefHostDisplayClientOSR::DidCompleteSwapWithNewSize(
     const gfx::Size& size) {}
 #endif
