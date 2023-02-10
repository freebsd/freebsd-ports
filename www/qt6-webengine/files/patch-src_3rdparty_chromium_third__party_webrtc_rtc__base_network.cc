--- src/3rdparty/chromium/third_party/webrtc/rtc_base/network.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/network.cc
@@ -261,7 +261,12 @@ AdapterType GetAdapterTypeFromName(const char* network
   }
 #endif
 
+#if defined(WEBRTC_BSD)
+  // Treat all other network interface names as ethernet on BSD
+  return ADAPTER_TYPE_ETHERNET;
+#else
   return ADAPTER_TYPE_UNKNOWN;
+#endif
 }
 
 NetworkManager::NetworkManager() {}
