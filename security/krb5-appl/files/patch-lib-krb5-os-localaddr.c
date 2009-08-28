--- lib/krb5/os/localaddr.c.orig	2009-02-18 10:14:48.000000000 -0800
+++ lib/krb5/os/localaddr.c	2009-08-28 13:37:41.000000000 -0700
@@ -173,6 +173,7 @@
 }
 #endif
 
+#if 0
 static int
 is_loopback_address(struct sockaddr *sa)
 {
@@ -189,6 +190,7 @@
 	return 0;
     }
 }
+#endif
 
 #ifdef HAVE_IFADDRS_H
 #include <ifaddrs.h>
@@ -464,12 +466,14 @@
 	    ifp->ifa_flags &= ~IFF_UP;
 	    continue;
 	}
+#if 0
 	if (is_loopback_address(ifp->ifa_addr)) {
 	    /* Pretend it's not up, so the second pass will skip
 	       it.  */
 	    ifp->ifa_flags &= ~IFF_UP;
 	    continue;
 	}
+#endif
 	/* If this address is a duplicate, punt.  */
 	match = 0;
 	for (ifp2 = ifp_head; ifp2 && ifp2 != ifp; ifp2 = ifp2->ifa_next) {
@@ -598,11 +602,13 @@
 	    }
 	    /*@=moduncon@*/
 
+#if 0
 	    /* None of the current callers want loopback addresses.  */
 	    if (is_loopback_address((struct sockaddr *)&lifr->lifr_addr)) {
 		Tprintf (("  loopback\n"));
 		goto skip;
 	    }
+#endif
 	    /* Ignore interfaces that are down.  */
 	    if ((lifreq.lifr_flags & IFF_UP) == 0) {
 		Tprintf (("  down\n"));
@@ -769,11 +775,13 @@
 	    }
 	    /*@=moduncon@*/
 
+#if 0
 	    /* None of the current callers want loopback addresses.  */
 	    if (is_loopback_address(&lifr->iflr_addr)) {
 		Tprintf (("  loopback\n"));
 		goto skip;
 	    }
+#endif
 	    /* Ignore interfaces that are down.  */
 	    if ((lifreq.iflr_flags & IFF_UP) == 0) {
 		Tprintf (("  down\n"));
@@ -984,11 +992,13 @@
 	}
 	/*@=moduncon@*/
 
+#if 0
 	/* None of the current callers want loopback addresses.  */
 	if (is_loopback_address(&ifreq.ifr_addr)) {
 	    Tprintf (("  loopback\n"));
 	    goto skip;
 	}
+#endif
 	/* Ignore interfaces that are down.  */
 	if ((ifreq.ifr_flags & IFF_UP) == 0) {
 	    Tprintf (("  down\n"));
