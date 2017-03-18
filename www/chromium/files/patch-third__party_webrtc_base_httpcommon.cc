--- third_party/webrtc/base/httpcommon.cc.orig	2017-03-09 20:05:29 UTC
+++ third_party/webrtc/base/httpcommon.cc
@@ -385,7 +385,7 @@ bool HttpDateToSeconds(const std::string
     gmt = non_gmt + kTimeZoneOffsets[zindex] * 60 * 60;
   }
   // TODO: Android should support timezone, see b/2441195
-#if defined(WEBRTC_MAC) && !defined(WEBRTC_IOS) || defined(WEBRTC_ANDROID) || defined(BSD)
+#if defined(WEBRTC_MAC) && !defined(WEBRTC_IOS) || defined(WEBRTC_ANDROID) || defined(WEBRTC_BSD)
   tm *tm_for_timezone = localtime(&gmt);
   *seconds = gmt + tm_for_timezone->tm_gmtoff;
 #else
