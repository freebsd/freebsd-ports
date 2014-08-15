--- ./media/cast/rtcp/rtcp.cc.orig	2014-08-12 21:02:56.000000000 +0200
+++ ./media/cast/rtcp/rtcp.cc	2014-08-13 09:56:57.000000000 +0200
@@ -361,7 +361,7 @@
   int64 rtp_time_diff_ms = rtp_timestamp_diff / frequency_khz;
 
   // Sanity check.
-  if (std::abs(rtp_time_diff_ms) > kMaxDiffSinceReceivedRtcpMs)
+  if (std::labs(rtp_time_diff_ms) > kMaxDiffSinceReceivedRtcpMs)
     return false;
 
   *rtp_timestamp_in_ticks = ConvertNtpToTimeTicks(last_received_ntp_seconds_,
