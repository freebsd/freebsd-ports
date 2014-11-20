--- net/quic/congestion_control/rtt_stats.cc.orig	2014-10-10 08:54:16 UTC
+++ net/quic/congestion_control/rtt_stats.cc
@@ -85,7 +85,7 @@
   } else {
     mean_deviation_ = QuicTime::Delta::FromMicroseconds(
         kOneMinusBeta * mean_deviation_.ToMicroseconds() +
-        kBeta * std::abs(smoothed_rtt_.Subtract(rtt_sample).ToMicroseconds()));
+        kBeta * std::labs(smoothed_rtt_.Subtract(rtt_sample).ToMicroseconds()));
     smoothed_rtt_ = smoothed_rtt_.Multiply(kOneMinusAlpha).Add(
         rtt_sample.Multiply(kAlpha));
     DVLOG(1) << " smoothed_rtt(us):" << smoothed_rtt_.ToMicroseconds()
