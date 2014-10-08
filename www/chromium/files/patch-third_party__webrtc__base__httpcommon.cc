--- third_party/webrtc/base/httpcommon.cc.orig	2014-10-02 17:40:33 UTC
+++ third_party/webrtc/base/httpcommon.cc
@@ -382,7 +382,7 @@
     gmt = non_gmt + kTimeZoneOffsets[zindex] * 60 * 60;
   }
   // TODO: Android should support timezone, see b/2441195
-#if defined(WEBRTC_MAC) && !defined(WEBRTC_IOS) || defined(WEBRTC_ANDROID) || defined(BSD)
+#if defined(WEBRTC_MAC) && !defined(WEBRTC_IOS) || defined(WEBRTC_ANDROID) || defined(WEBRTC_BSD)
   tm *tm_for_timezone = localtime((time_t *)&gmt);
   *seconds = gmt + tm_for_timezone->tm_gmtoff;
 #else
