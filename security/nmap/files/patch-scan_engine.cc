$FreeBSD$

Patch taken from <20060217013528.GG7214@syn.lnxnet.net>.
http://seclists.org/lists/nmap-dev/2006/Jan-Mar/0205.html
Will be included in nmap 4.02.

--- scan_engine.cc.ORIG	Wed Mar  8 13:36:06 2006
+++ scan_engine.cc	Wed Mar  8 13:40:44 2006
@@ -807,6 +807,7 @@
 
   /* Returns true if the GLOBAL system says that sending is OK.*/
 bool GroupScanStats::sendOK() {
+  int recentsends;
 
   if (USI->scantype == CONNECT_SCAN && CSI->numSDs >= CSI->maxSocketsAllowed)
     return false;
@@ -815,7 +816,9 @@
      the last listen call, at least for systems such as Windoze that
      don't give us a proper pcap time.  Also for connect scans, since
      we don't get an exact response time with them either. */
-  if (USI->scantype == CONNECT_SCAN || !pcap_recv_timeval_valid()) {
+  recentsends = USI->gstats->probes_sent - USI->gstats->probes_sent_at_last_wait;
+  if (recentsends > 0 &&
+     (USI->scantype == CONNECT_SCAN || !pcap_recv_timeval_valid())) {
     int to_ms = (int) MAX(to.srtt * .75 / 1000, 50);
     if (TIMEVAL_MSEC_SUBTRACT(USI->now, last_wait) > to_ms)
       return false;
@@ -828,7 +831,7 @@
      responses when I scan localhost.  And half of those are the @#$#
      sends being received.  I think I'll put a limit of 50 sends per
      wait */
-  if (USI->gstats->probes_sent - USI->gstats->probes_sent_at_last_wait >= 50)
+  if (recentsends >= 50)
     return false;
 
   /* When there is only one target left, let the host congestion
@@ -969,7 +972,7 @@
 
   getTiming(&tmng);
   if (tmng.cwnd >= num_probes_active + .5 && 
-      (freshPortsLeft() || num_probes_waiting_retransmit)) {
+      (freshPortsLeft() || num_probes_waiting_retransmit || !retry_stack.empty())) {
     if (when) *when = USI->now;
     return true;
   }
