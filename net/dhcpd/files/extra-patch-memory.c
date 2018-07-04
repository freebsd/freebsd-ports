--- memory.c.orig	2018-06-06 09:14:19 UTC
+++ memory.c
@@ -619,9 +619,11 @@ supersede_lease(struct lease *comp, stru
 		comp->ends = lease->ends;
 	}
 
+#ifndef NO_PF
 	pfmsg('L', lease); /* address is leased. remove from purgatory */
 	if (do_pftable) /* address changed hwaddr. remove from overload */
 		pfmsg('C', lease);
+#endif /* NO_PF */
 
 	/* Return zero if we didn't commit the lease to permanent storage;
 	   nonzero if we did. */
@@ -641,7 +643,9 @@ release_lease(struct lease *lease)
 		supersede_lease(lease, &lt, 1);
 		note("Released lease for IP address %s",
 		    piaddr(lease->ip_addr));
+#ifndef NO_PF
 		pfmsg('R', lease);
+#endif /* NO_PF */
 	}
 }
 
@@ -669,7 +673,9 @@ abandon_lease(struct lease *lease, char 
 	lt.uid_len = 0;
 	supersede_lease(lease, &lt, 1);
 
+#ifndef NO_PF
 	pfmsg('A', lease); /* address is abandoned. send to purgatory */
+#endif /* NO_PF */
 	return;
 }
 
