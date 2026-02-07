--- third_party/webrtc/rtc_base/network.cc.orig	2026-01-16 13:40:34 UTC
+++ third_party/webrtc/rtc_base/network.cc
@@ -304,7 +304,12 @@ AdapterType GetAdapterTypeFromName(absl::string_view n
   }
 #endif
 
+#if defined(WEBRTC_BSD)
+  // Treat all other network interface names as ethernet on BSD
+  return webrtc::ADAPTER_TYPE_ETHERNET;
+#else
   return ADAPTER_TYPE_UNKNOWN;
+#endif
 }
 
 NetworkManager::EnumerationPermission NetworkManager::enumeration_permission()
