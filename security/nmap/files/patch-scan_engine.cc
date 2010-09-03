--- ./scan_engine.cc.orig	2010-06-22 19:24:34.000000000 +0200
+++ ./scan_engine.cc	2010-09-03 21:04:29.000000000 +0200
@@ -4124,7 +4124,7 @@
       }
     } else if (ip->ip_p == IPPROTO_SCTP && !USI->prot_scan) {
       struct sctp_hdr *sctp = (struct sctp_hdr *) ((u8 *) ip + ip->ip_hl * 4);
-      struct sctp_chunkhdr *chunk = (struct sctp_chunkhdr *) ((u8 *) sctp + 12);
+      struct dnet_sctp_chunkhdr *chunk = (struct dnet_sctp_chunkhdr *) ((u8 *) sctp + 12);
       /* Now ensure this host is even in the incomplete list */
       memset(&sin, 0, sizeof(sin));
       sin.sin_addr.s_addr = ip->ip_src.s_addr;
@@ -4737,7 +4737,7 @@
       }
     } else if (ip->ip_p == IPPROTO_SCTP && USI->ptech.rawsctpscan) {
       struct sctp_hdr *sctp = (struct sctp_hdr *) (((char *) ip) + 4 * ip->ip_hl);
-      struct sctp_chunkhdr *chunk = (struct sctp_chunkhdr *) ((u8 *) sctp + 12);
+      struct dnet_sctp_chunkhdr *chunk = (struct dnet_sctp_chunkhdr *) ((u8 *) sctp + 12);
       /* Search for this host on the incomplete list */
       memset(&sin, 0, sizeof(sin));
       sin.sin_addr.s_addr = ip->ip_src.s_addr;
