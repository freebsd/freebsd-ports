--- net/dns/dns_session.cc.orig	2016-05-11 19:02:24 UTC
+++ net/dns/dns_session.cc
@@ -190,7 +190,7 @@ void DnsSession::RecordRTT(unsigned serv
   base::TimeDelta current_error = rtt - estimate;
   estimate += current_error / 8;  // * alpha
   base::TimeDelta abs_error = base::TimeDelta::FromInternalValue(
-      std::abs(current_error.ToInternalValue()));
+      std::labs(current_error.ToInternalValue()));
   deviation += (abs_error - deviation) / 4;  // * delta
 
   // Histogram-based method.
