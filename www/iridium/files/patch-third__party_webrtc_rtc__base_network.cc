--- third_party/webrtc/rtc_base/network.cc.orig	2025-06-19 07:37:57 UTC
+++ third_party/webrtc/rtc_base/network.cc
@@ -316,7 +316,12 @@ AdapterType GetAdapterTypeFromName(absl::string_view n
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
