--- src/3rdparty/chromium/third_party/webrtc/rtc_base/network.cc.orig	2023-02-08 09:03:45 UTC
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/network.cc
@@ -288,7 +288,12 @@ AdapterType GetAdapterTypeFromName(absl::string_view n
   }
 #endif
 
+#if defined(WEBRTC_BSD)
+  // Treat all other network interface names as ethernet on BSD
+  return ADAPTER_TYPE_ETHERNET;
+#else
   return ADAPTER_TYPE_UNKNOWN;
+#endif
 }
 
 NetworkManager::EnumerationPermission NetworkManager::enumeration_permission()
