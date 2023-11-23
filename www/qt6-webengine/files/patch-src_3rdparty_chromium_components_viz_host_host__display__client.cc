--- src/3rdparty/chromium/components/viz/host/host_display_client.cc.orig	2023-03-09 06:31:50 UTC
+++ src/3rdparty/chromium/components/viz/host/host_display_client.cc
@@ -67,7 +67,7 @@ void HostDisplayClient::AddChildWindowToBrowser(
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 void HostDisplayClient::DidCompleteSwapWithNewSize(const gfx::Size& size) {
   NOTIMPLEMENTED();
 }
