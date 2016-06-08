--- net/quic/congestion_control/rtt_stats.cc.orig	2014-05-14 21:22:13.000000000 +0200
+++ net/quic/congestion_control/rtt_stats.cc	2014-05-21 23:32:04.000000000 +0200
@@ -63,7 +63,7 @@
   } else {
     mean_deviation_ = QuicTime::Delta::FromMicroseconds(
         kOneMinusBeta * mean_deviation_.ToMicroseconds() +
-        kBeta * std::abs(smoothed_rtt_.Subtract(rtt_sample).ToMicroseconds()));
+        kBeta * std::labs(smoothed_rtt_.Subtract(rtt_sample).ToMicroseconds()));
     smoothed_rtt_ = smoothed_rtt_.Multiply(kOneMinusAlpha).Add(
         rtt_sample.Multiply(kAlpha));
     DVLOG(1) << "Cubic; smoothed_rtt(us):" << smoothed_rtt_.ToMicroseconds()
