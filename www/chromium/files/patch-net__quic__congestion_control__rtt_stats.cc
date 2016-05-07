--- net/quic/congestion_control/rtt_stats.cc.orig	2016-03-05 11:59:07.038865734 +0100
+++ net/quic/congestion_control/rtt_stats.cc	2016-03-05 11:59:48.890863022 +0100
@@ -4,7 +4,7 @@
 
 #include "net/quic/congestion_control/rtt_stats.h"
 
-#include <cstdlib>  // std::abs
+#include <cstdlib>  // std::labs
 
 using std::max;
 
@@ -41,7 +41,7 @@
   mean_deviation_ =
       max(mean_deviation_,
           QuicTime::Delta::FromMicroseconds(
-              std::abs(smoothed_rtt_.Subtract(latest_rtt_).ToMicroseconds())));
+              std::labs(smoothed_rtt_.Subtract(latest_rtt_).ToMicroseconds())));
   smoothed_rtt_ = max(smoothed_rtt_, latest_rtt_);
 }
 
@@ -81,7 +81,7 @@
   } else {
     mean_deviation_ = QuicTime::Delta::FromMicroseconds(static_cast<int64_t>(
         kOneMinusBeta * mean_deviation_.ToMicroseconds() +
-        kBeta * std::abs(smoothed_rtt_.Subtract(rtt_sample).ToMicroseconds())));
+        kBeta * std::labs(smoothed_rtt_.Subtract(rtt_sample).ToMicroseconds())));
     smoothed_rtt_ =
         smoothed_rtt_.Multiply(kOneMinusAlpha).Add(rtt_sample.Multiply(kAlpha));
     DVLOG(1) << " smoothed_rtt(us):" << smoothed_rtt_.ToMicroseconds()
