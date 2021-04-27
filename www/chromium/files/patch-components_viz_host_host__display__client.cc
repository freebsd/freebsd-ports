--- components/viz/host/host_display_client.cc.orig	2021-04-14 18:41:02 UTC
+++ components/viz/host/host_display_client.cc
@@ -60,7 +60,7 @@ void HostDisplayClient::CreateLayeredWindowUpdater(
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 void HostDisplayClient::DidCompleteSwapWithNewSize(const gfx::Size& size) {
   NOTIMPLEMENTED();
 }
