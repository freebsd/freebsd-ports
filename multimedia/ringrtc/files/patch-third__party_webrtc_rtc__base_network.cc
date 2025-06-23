--- src/webrtc/src/rtc_base/network.cc.orig	2024-06-17 12:56:06 UTC
+++ src/webrtc/src/rtc_base/network.cc
@@ -320,7 +320,12 @@ webrtc::AdapterType GetAdapterTypeFromName(absl::strin
   }
 #endif
 
-  return webrtc::ADAPTER_TYPE_UNKNOWN;
+#if defined(WEBRTC_BSD)
+  // Treat all other network interface names as ethernet on BSD
+  return ADAPTER_TYPE_ETHERNET;
+#else
+   return ADAPTER_TYPE_UNKNOWN;
+#endif
 }
 
 NetworkManager::EnumerationPermission NetworkManager::enumeration_permission()
