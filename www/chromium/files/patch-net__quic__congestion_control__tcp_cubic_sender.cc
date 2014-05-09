--- net/quic/congestion_control/tcp_cubic_sender.cc.orig	2014-04-24 22:35:53.000000000 +0200
+++ net/quic/congestion_control/tcp_cubic_sender.cc	2014-05-09 10:57:21.000000000 +0200
@@ -341,7 +341,7 @@
     mean_deviation_ = QuicTime::Delta::FromMicroseconds(
         kOneMinusBeta * mean_deviation_.ToMicroseconds() +
         kBeta *
-            std::abs(smoothed_rtt_.ToMicroseconds() - rtt.ToMicroseconds()));
+            std::labs(smoothed_rtt_.ToMicroseconds() - rtt.ToMicroseconds()));
     smoothed_rtt_ = QuicTime::Delta::FromMicroseconds(
         kOneMinusAlpha * smoothed_rtt_.ToMicroseconds() +
         kAlpha * rtt.ToMicroseconds());
