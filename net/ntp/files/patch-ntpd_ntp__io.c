--- ntpd/ntp_io.c.orig	2024-05-07 04:21:17.000000000 -0700
+++ ntpd/ntp_io.c	2025-02-18 19:31:18.434141000 -0800
@@ -3205,7 +3205,7 @@
 	}
 
 	do {
-		if (INT_LL_OF_GLOB & src->flags) {
+		if (ismcast && INT_LL_OF_GLOB & src->flags) {
 			/* avoid duplicate multicasts on same IPv6 net */
 			goto loop;
 		}
