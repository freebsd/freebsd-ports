--- third_party/webrtc/rtc_base/network.cc.orig	2020-05-13 18:41:57 UTC
+++ third_party/webrtc/rtc_base/network.cc
@@ -222,7 +222,12 @@ AdapterType GetAdapterTypeFromName(const char* network
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
