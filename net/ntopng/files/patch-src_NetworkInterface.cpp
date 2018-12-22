--- src/NetworkInterface.cpp.orig	2018-12-21 18:58:17 UTC
+++ src/NetworkInterface.cpp
@@ -6772,7 +6772,11 @@ bool NetworkInterface::matchLiveCapture(struct ntopngL
      || (luactx->live_capture.matching_host == f->get_srv_host())) {
     if(luactx->live_capture.bpfFilterSet) {
       if(!bpf_filter(luactx->live_capture.fcode.bf_insns,
+#if __FreeBSD_version >= 1100514
 		     (const u_char*)packet, h->caplen, h->caplen)) {
+#else
+		     (u_char*)packet, h->caplen, h->caplen)) {
+#endif
 	return(false);
       }
     }
