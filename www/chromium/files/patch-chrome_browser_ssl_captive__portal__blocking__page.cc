--- chrome/browser/ssl/captive_portal_blocking_page.cc.orig	2020-03-03 18:53:52 UTC
+++ chrome/browser/ssl/captive_portal_blocking_page.cc
@@ -135,7 +135,7 @@ std::string CaptivePortalBlockingPage::GetWiFiSSID() c
   wifi_service->GetConnectedNetworkSSID(&ssid, &error);
   if (!error.empty())
     return std::string();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   ssid = net::GetWifiSSID();
 #elif defined(OS_ANDROID)
   ssid = net::android::GetWifiSSID();
