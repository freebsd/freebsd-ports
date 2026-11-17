--- src/components/viz/host/host_display_client.cc.orig	2026-10-18 18:43:23 UTC
+++ src/components/viz/host/host_display_client.cc
@@ -67,7 +67,7 @@ void HostDisplayClient::AddChildWindowTo
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(SUPPORTS_OZONE_X11)
 void HostDisplayClient::DidCompleteSwapWithNewSize(const gfx::Size& size) {
   NOTIMPLEMENTED();
 }
