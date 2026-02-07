--- ntpd/ntp_io.c.orig	2024-05-07 04:21:17.000000000 -0700
+++ ntpd/ntp_io.c	2025-11-20 19:55:01.228924000 -0800
@@ -1486,9 +1486,7 @@
 
 	if (IS_IPV6(psau)) {
 		p6addr = &psau->sa6.sin6_addr;
-		if (   IN6_IS_ADDR_LINKLOCAL(p6addr)
-		    || IN6_IS_ADDR_SITELOCAL(p6addr)) {
-
+		if (IN6_IS_ADDR_LINKLOCAL(p6addr)) {
 			return TRUE;
 		}
 	} else if (IS_IPV4(psau)) {
@@ -1921,11 +1919,11 @@
 		}
 		else {
 			DPRINT_INTERFACE(3,
-				(ep, "updating ", " new - FAILED"));
+				(ep2, "updating ", " new - FAILED"));
 
 			msyslog(LOG_ERR,
 				"cannot bind address %s",
-				stoa(&ep->sin));
+				stoa(&ep2->sin));
 		}
 		free(ep2);
 	}
@@ -3205,7 +3203,7 @@
 	}
 
 	do {
-		if (INT_LL_OF_GLOB & src->flags) {
+		if (ismcast && INT_LL_OF_GLOB & src->flags) {
 			/* avoid duplicate multicasts on same IPv6 net */
 			goto loop;
 		}
