--- a/tools/udp_pes_scheduler.c.orig	2012-05-11 07:37:27 UTC
+++ b/tools/udp_pes_scheduler.c
@@ -674,7 +674,7 @@ void cUdpScheduler::Schedule(const uchar
 
   if (DATA_IS_TS(Data)) {
     if (ts_get_pcr_n(Data, Length/TS_SIZE, &pts)) {
-      LOGSCR("UDP PCR: %"PRId64, pts);
+      LOGSCR("UDP PCR: %" PRId64, pts);
       ScrSource = eScrFromPcr;
       elapsed   = CalcElapsedVtime(pts, eScrFromPcr);
     }
