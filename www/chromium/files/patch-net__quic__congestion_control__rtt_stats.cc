--- net/quic/congestion_control/rtt_stats.cc.orig	2015-04-19 16:49:03.000000000 +0200
+++ net/quic/congestion_control/rtt_stats.cc	2015-04-19 16:49:19.000000000 +0200
@@ -81,7 +81,7 @@
   } else {
     mean_deviation_ = QuicTime::Delta::FromMicroseconds(static_cast<int64>(
         kOneMinusBeta * mean_deviation_.ToMicroseconds() +
-        kBeta * std::abs(smoothed_rtt_.Subtract(rtt_sample).ToMicroseconds())));
+        kBeta * std::labs(smoothed_rtt_.Subtract(rtt_sample).ToMicroseconds())));
     smoothed_rtt_ = smoothed_rtt_.Multiply(kOneMinusAlpha).Add(
         rtt_sample.Multiply(kAlpha));
     DVLOG(1) << " smoothed_rtt(us):" << smoothed_rtt_.ToMicroseconds()
