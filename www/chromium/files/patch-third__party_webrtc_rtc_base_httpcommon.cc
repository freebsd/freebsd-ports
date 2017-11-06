--- third_party/webrtc/rtc_base/httpcommon.cc.orig	2017-09-07 00:39:17.532376000 +0200
+++ third_party/webrtc/rtc_base/httpcommon.cc	2017-09-07 00:41:55.817287000 +0200
@@ -384,7 +384,7 @@
     gmt = non_gmt + kTimeZoneOffsets[zindex] * 60 * 60;
   }
   // TODO: Android should support timezone, see b/2441195
-#if defined(WEBRTC_MAC) && !defined(WEBRTC_IOS) || defined(WEBRTC_ANDROID) || defined(BSD)
+#if defined(WEBRTC_MAC) && !defined(WEBRTC_IOS) || defined(WEBRTC_ANDROID) || defined(WEBRTC_BSD)
   tm *tm_for_timezone = localtime(&gmt);
   *seconds = gmt + tm_for_timezone->tm_gmtoff;
 #else
