--- media/cast/rtcp/rtcp.cc.orig	2014-05-14 21:23:34.000000000 +0200
+++ media/cast/rtcp/rtcp.cc	2014-05-22 09:51:16.000000000 +0200
@@ -362,7 +362,7 @@
   int64 rtp_time_diff_ms = rtp_timestamp_diff / frequency_khz;
 
   // Sanity check.
-  if (std::abs(rtp_time_diff_ms) > kMaxDiffSinceReceivedRtcpMs)
+  if (std::labs(rtp_time_diff_ms) > kMaxDiffSinceReceivedRtcpMs)
     return false;
 
   *rtp_timestamp_in_ticks = ConvertNtpToTimeTicks(last_received_ntp_seconds_,
