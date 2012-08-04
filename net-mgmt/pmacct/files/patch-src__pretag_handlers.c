--- ./src/pretag_handlers.c.orig	2012-08-03 23:29:51.000000000 -0400
+++ ./src/pretag_handlers.c	2012-08-03 23:30:23.000000000 -0400
@@ -1067,7 +1067,7 @@
   if (entry->last_matched == PRETAG_BGP_NEXTHOP) return FALSE;
 
   /* check network-related primitives against fallback scenarios */
-  if (!evaluate_lm_method(pptrs, TRUE, config.nfacctd_net, NF_NET_KEEP)) return;
+  if (!evaluate_lm_method(pptrs, TRUE, config.nfacctd_net, NF_NET_KEEP)) return 0;
 
   switch(hdr->version) {
   case 9:
@@ -1100,7 +1100,7 @@
   int ret = -1;
 
   /* check network-related primitives against fallback scenarios */
-  if (!evaluate_lm_method(pptrs, TRUE, config.nfacctd_net, NF_NET_BGP)) return;
+  if (!evaluate_lm_method(pptrs, TRUE, config.nfacctd_net, NF_NET_BGP)) return 0;
 
   if (dst_ret) {
     if (pptrs->bgp_nexthop_info)
@@ -1660,7 +1660,7 @@
   SFSample *sample = (SFSample *) pptrs->f_data;
 
   /* check network-related primitives against fallback scenarios */
-  if (!evaluate_lm_method(pptrs, TRUE, config.nfacctd_net, NF_NET_KEEP)) return;
+  if (!evaluate_lm_method(pptrs, TRUE, config.nfacctd_net, NF_NET_KEEP)) return 0;
 
   if (entry->bgp_nexthop.a.family == AF_INET) {
     if (!memcmp(&entry->bgp_nexthop.a.address.ipv4, &sample->bgp_nextHop.address.ip_v4, 4)) return (FALSE | entry->bgp_nexthop.neg);
