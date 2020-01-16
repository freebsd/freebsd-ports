--- components/viz/host/host_display_client.cc.orig	2019-12-17 19:29:17 UTC
+++ components/viz/host/host_display_client.cc
@@ -59,7 +59,7 @@ void HostDisplayClient::CreateLayeredWindowUpdater(
 }
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 void HostDisplayClient::DidCompleteSwapWithNewSize(const gfx::Size& size) {
   NOTIMPLEMENTED();
 }
