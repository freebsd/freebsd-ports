--- src/3rdparty/chromium/components/viz/host/host_display_client.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/viz/host/host_display_client.cc
@@ -65,7 +65,7 @@ void HostDisplayClient::AddChildWindowToBrowser(
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
 void HostDisplayClient::DidCompleteSwapWithNewSize(const gfx::Size& size) {
   NOTIMPLEMENTED();
 }
