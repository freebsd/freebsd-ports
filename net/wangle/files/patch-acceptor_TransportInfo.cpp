--- acceptor/TransportInfo.cpp.orig	2020-09-08 16:56:17 UTC
+++ acceptor/TransportInfo.cpp
@@ -42,6 +42,16 @@ bool TransportInfo::initWithSocket(const folly::AsyncS
   if (mss > 0) {
     cwnd = (cwndBytes + mss - 1) / mss;
   }
+#elif defined(__FreeBSD__)
+  rtt = microseconds(tcpinfo.tcpi_rtt * 1000);
+  rtt_var = tcpinfo.tcpi_rttvar * 1000;
+  rto = tcpinfo.tcpi_rto * 1000;
+  rtx_tm = -1;
+  mss = tcpinfo.tcpi_snd_mss;
+  cwndBytes = tcpinfo.tcpi_snd_cwnd;
+  if (mss > 0) {
+    cwnd = (cwndBytes + mss - 1) / mss;
+  }
 #else
   rtt = microseconds(tcpinfo.tcpi_rtt);
   rtt_var = tcpinfo.tcpi_rttvar;
