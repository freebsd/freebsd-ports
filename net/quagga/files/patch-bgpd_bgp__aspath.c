--- bgpd/bgp_aspath.c.orig	2017-10-03 14:57:10 UTC
+++ bgpd/bgp_aspath.c
@@ -901,7 +901,7 @@ aspath_put (struct stream *s, struct aspath *as, int u
           while ( (seg->length - written) > AS_SEGMENT_MAX)
             {
               assegment_header_put (s, seg->type, AS_SEGMENT_MAX);
-              assegment_data_put (s, seg->as, AS_SEGMENT_MAX, use32bit);
+              assegment_data_put (s, (seg->as+written), AS_SEGMENT_MAX, use32bit);
               written += AS_SEGMENT_MAX;
               bytes += ASSEGMENT_SIZE (AS_SEGMENT_MAX, use32bit);
             }
