--- third_party/webrtc/rtc_base/network.cc.orig	2025-05-06 12:23:00 UTC
+++ third_party/webrtc/rtc_base/network.cc
@@ -314,7 +314,12 @@ webrtc::AdapterType GetAdapterTypeFromName(absl::strin
   }
 #endif
 
+#if defined(WEBRTC_BSD)
+  // Treat all other network interface names as ethernet on BSD
+  return webrtc::ADAPTER_TYPE_ETHERNET;
+#else
   return webrtc::ADAPTER_TYPE_UNKNOWN;
+#endif
 }
 
 NetworkManager::EnumerationPermission NetworkManager::enumeration_permission()
