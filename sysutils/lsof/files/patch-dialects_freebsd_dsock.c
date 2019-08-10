--- dialects/freebsd/dsock.c.orig	2019-05-08 07:32:25 UTC
+++ dialects/freebsd/dsock.c
@@ -182,7 +182,7 @@ process_socket(sa)
 #endif	/* FREEBSDV<4050 */
 
 #if	defined(HASIPv6) && !defined(HASINRIAIPv6)
-	struct in6pcb in6p;
+	struct inpcb in6p;
 #endif	/* defined(HASIPv6) && !defined(HASINRIAIPv6) */
 
 	(void) snpf(Lf->type, sizeof(Lf->type), "sock");
