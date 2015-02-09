--- net/quic/congestion_control/inter_arrival_overuse_detector.cc.orig	2014-04-24 22:35:53.000000000 +0200
+++ net/quic/congestion_control/inter_arrival_overuse_detector.cc	2014-05-09 10:29:30.000000000 +0200
@@ -165,7 +165,7 @@
   if ((sigma_delta * kDetectTimeDiffStandardDeviation >
        estimated_congestion_delay_.ToMicroseconds()) &&
       (sigma_delta * kDetectDriftStandardDeviation >
-       std::abs(accumulated_deltas_.ToMicroseconds()))) {
+       std::labs(accumulated_deltas_.ToMicroseconds()))) {
     if (delta_estimate_ != kBandwidthSteady) {
       DVLOG(1) << "Bandwidth estimate drift: Steady"
                  << " mean:" << delta_mean_
