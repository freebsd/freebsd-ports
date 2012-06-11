--- ./bgpd/bgp_open.c.orig	2012-05-01 12:10:27.000000000 -0400
+++ ./bgpd/bgp_open.c	2012-06-10 09:05:40.000000000 -0400
@@ -232,7 +232,7 @@
     }
   
   /* validate number field */
-  if (sizeof (struct capability_orf_entry) + (entry.num * 2) > hdr->length)
+  if (sizeof (struct capability_orf_entry) + (entry.num * 2) != hdr->length)
     {
       zlog_info ("%s ORF Capability entry length error,"
                  " Cap length %u, num %u",
@@ -336,28 +336,6 @@
 }
 
 static int
-bgp_capability_orf (struct peer *peer, struct capability_header *hdr)
-{
-  struct stream *s = BGP_INPUT (peer);
-  size_t end = stream_get_getp (s) + hdr->length;
-  
-  assert (stream_get_getp(s) + sizeof(struct capability_orf_entry) <= end);
-  
-  /* We must have at least one ORF entry, as the caller has already done
-   * minimum length validation for the capability code - for ORF there must
-   * at least one ORF entry (header and unknown number of pairs of bytes).
-   */
-  do
-    {
-      if (bgp_capability_orf_entry (peer, hdr) == -1)
-        return -1;
-    } 
-  while (stream_get_getp(s) + sizeof(struct capability_orf_entry) < end);
-  
-  return 0;
-}
-
-static int
 bgp_capability_restart (struct peer *peer, struct capability_header *caphdr)
 {
   struct stream *s = BGP_INPUT (peer);
@@ -575,7 +553,7 @@
             break;
           case CAPABILITY_CODE_ORF:
           case CAPABILITY_CODE_ORF_OLD:
-            if (bgp_capability_orf (peer, &caphdr))
+            if (bgp_capability_orf_entry (peer, &caphdr))
               return -1;
             break;
           case CAPABILITY_CODE_RESTART:
