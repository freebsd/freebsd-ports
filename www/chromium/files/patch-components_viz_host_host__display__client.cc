--- components/viz/host/host_display_client.cc.orig	2026-03-13 06:02:14 UTC
+++ components/viz/host/host_display_client.cc
@@ -66,7 +66,7 @@ void HostDisplayClient::AddChildWindowToBrowser(
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(SUPPORTS_OZONE_X11)
 void HostDisplayClient::DidCompleteSwapWithNewSize(const gfx::Size& size) {
   NOTIMPLEMENTED();
 }
