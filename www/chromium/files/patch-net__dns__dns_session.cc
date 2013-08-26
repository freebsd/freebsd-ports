--- net/dns/dns_session.cc.orig	2013-08-19 01:54:01.000000000 +0200
+++ net/dns/dns_session.cc	2013-08-26 12:42:02.000000000 +0200
@@ -176,7 +176,7 @@
   base::TimeDelta current_error = rtt - estimate;
   estimate += current_error / 8;  // * alpha
   base::TimeDelta abs_error = base::TimeDelta::FromInternalValue(
-      std::abs(current_error.ToInternalValue()));
+      std::labs(current_error.ToInternalValue()));
   deviation += (abs_error - deviation) / 4;  // * delta
 
   // Histogram-based method.
