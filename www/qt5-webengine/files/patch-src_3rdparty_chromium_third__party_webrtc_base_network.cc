--- src/3rdparty/chromium/third_party/webrtc/base/network.cc.orig	2017-01-26 00:50:17 UTC
+++ src/3rdparty/chromium/third_party/webrtc/base/network.cc
@@ -14,7 +14,7 @@
 // linux/if.h can't be included at the same time as the posix sys/if.h, and
 // it's transitively required by linux/route.h, so include that version on
 // linux instead of the standard posix one.
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)
 #include <linux/if.h>
 #include <linux/route.h>
 #elif !defined(__native_client__)
@@ -656,7 +656,7 @@ bool BasicNetworkManager::CreateNetworks
 }
 #endif  // WEBRTC_WIN
 
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)
 bool IsDefaultRoute(const std::string& network_name) {
   FileStream fs;
   if (!fs.Open("/proc/net/route", "r", NULL)) {
@@ -699,7 +699,7 @@ bool BasicNetworkManager::IsIgnoredNetwo
       strncmp(network.name().c_str(), "vboxnet", 7) == 0) {
     return true;
   }
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)
   // Make sure this is a default route, if we're ignoring non-defaults.
   if (ignore_non_default_routes_ && !IsDefaultRoute(network.name())) {
     return true;
