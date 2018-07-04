--- dhcp.c.orig	2018-06-06 09:10:04 UTC
+++ dhcp.c
@@ -154,6 +154,7 @@ dhcpdiscover(struct packet *packet)
 			 * If we can't find an unabandoned lease,
 			 * reclaim the abandoned lease.
 			 */
+#ifndef NO_PF
 			if ((lease->flags & ABANDONED_LEASE)) {
 				warning("Reclaiming abandoned IP address %s.",
 				    piaddr(lease->ip_addr));
@@ -161,6 +162,7 @@ dhcpdiscover(struct packet *packet)
 
 				pfmsg('L', lease); /* unabandon address */
 			}
+#endif /* NO_PF */
 		}
 
 		/* Try to find a host_decl that matches the client
