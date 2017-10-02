--- bgpd/bgp_aspath.c.orig	2017-03-10 12:55:06 UTC
+++ bgpd/bgp_aspath.c
@@ -903,7 +903,7 @@ aspath_put (struct stream *s, struct aspath *as, int u
               assegment_header_put (s, seg->type, AS_SEGMENT_MAX);
               assegment_data_put (s, seg->as, AS_SEGMENT_MAX, use32bit);
               written += AS_SEGMENT_MAX;
-              bytes += ASSEGMENT_SIZE (written, use32bit);
+              bytes += ASSEGMENT_SIZE (AS_SEGMENT_MAX, use32bit);
             }
           
           /* write the final segment, probably is also the first */
