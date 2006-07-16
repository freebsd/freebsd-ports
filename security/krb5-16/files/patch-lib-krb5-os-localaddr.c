--- lib/krb5/os/localaddr.c.orig	Wed Apr 13 09:55:43 2005
+++ lib/krb5/os/localaddr.c	Sun Jul 16 09:29:05 2006
@@ -436,12 +436,14 @@
 #endif
 	if ((ifp->ifa_flags & IFF_UP) == 0)
 	    continue;
+#if 0
 	if (ifp->ifa_flags & IFF_LOOPBACK) {
 	    /* Pretend it's not up, so the second pass will skip
 	       it.  */
 	    ifp->ifa_flags &= ~IFF_UP;
 	    continue;
 	}
+#endif
 	if (ifp->ifa_addr == NULL) {
 	    /* Can't use an interface without an address.  Linux
 	       apparently does this sometimes.  [RT ticket 1770 from
@@ -459,8 +461,10 @@
 	for (ifp2 = ifp_head; ifp2 && ifp2 != ifp; ifp2 = ifp2->ifa_next) {
 	    if ((ifp2->ifa_flags & IFF_UP) == 0)
 		continue;
+#if 0
 	    if (ifp2->ifa_flags & IFF_LOOPBACK)
 		continue;
+#endif
 	    if (addr_eq (ifp->ifa_addr, ifp2->ifa_addr)) {
 		match = 1;
 		ifp->ifa_flags &= ~IFF_UP;
@@ -583,6 +587,7 @@
 	    }
 	    /*@=moduncon@*/
 
+#if 0
 #ifdef IFF_LOOPBACK
 	    /* None of the current callers want loopback addresses.  */
 	    if (lifreq.lifr_flags & IFF_LOOPBACK) {
@@ -590,6 +595,7 @@
 		goto skip;
 	    }
 #endif
+#endif
 	    /* Ignore interfaces that are down.  */
 	    if ((lifreq.lifr_flags & IFF_UP) == 0) {
 		Tprintf (("  down\n"));
@@ -755,6 +761,7 @@
 	    }
 	    /*@=moduncon@*/
 
+#if 0
 #ifdef IFF_LOOPBACK
 	    /* None of the current callers want loopback addresses.  */
 	    if (lifreq.iflr_flags & IFF_LOOPBACK) {
@@ -762,6 +769,7 @@
 		goto skip;
 	    }
 #endif
+#endif
 	    /* Ignore interfaces that are down.  */
 	    if ((lifreq.iflr_flags & IFF_UP) == 0) {
 		Tprintf (("  down\n"));
@@ -971,12 +979,14 @@
 	}
 	/*@=moduncon@*/
 
+#if 0
 #ifdef IFF_LOOPBACK
 	/* None of the current callers want loopback addresses.  */
 	if (ifreq.ifr_flags & IFF_LOOPBACK) {
 	    Tprintf (("  loopback\n"));
 	    goto skip;
 	}
+#endif
 #endif
 	/* Ignore interfaces that are down.  */
 	if ((ifreq.ifr_flags & IFF_UP) == 0) {
