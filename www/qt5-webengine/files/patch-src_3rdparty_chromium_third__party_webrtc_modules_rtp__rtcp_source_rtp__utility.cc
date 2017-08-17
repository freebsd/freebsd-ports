--- src/3rdparty/chromium/third_party/webrtc/modules/rtp_rtcp/source/rtp_utility.cc.orig	2017-04-20 13:10:18 UTC
+++ src/3rdparty/chromium/third_party/webrtc/modules/rtp_rtcp/source/rtp_utility.cc
@@ -57,7 +57,7 @@ bool StringCompare(const char* str1, con
                    const uint32_t length) {
   return _strnicmp(str1, str2, length) == 0;
 }
-#elif defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_MAC) || defined(BSD)
 bool StringCompare(const char* str1, const char* str2,
                    const uint32_t length) {
   return strncasecmp(str1, str2, length) == 0;
