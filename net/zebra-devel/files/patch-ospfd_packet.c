--- ospfd/ospf_packet.c.orig	Thu Jul  4 05:06:41 2002
+++ ospfd/ospf_packet.c	Fri Mar 28 00:05:26 2003
@@ -276,7 +276,7 @@
 
   /* check crypto seqnum. */
   nbr = ospf_nbr_lookup_by_routerid (oi->nbrs, &ospfh->router_id);
-  if (nbr && ntohl(nbr->crypt_seqnum) >= ntohl(ospfh->u.crypt.crypt_seqnum))
+  if (nbr && ntohl(nbr->crypt_seqnum) > ntohl(ospfh->u.crypt.crypt_seqnum))
     return 0;
       
   /* Generate a digest for the ospf packet - their digest + our digest. */
