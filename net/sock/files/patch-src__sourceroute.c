--- src/sourceroute.c.orig	2010-05-28 00:03:25 UTC
+++ src/sourceroute.c
@@ -88,10 +88,11 @@ sroute_set(int sockfd)
 	sroute_opt[1] = 3 + (sroute_cnt * 4); /* total length, incl. destination */
 
 	/* destination must be stored as final entry */
-	bcopy(&servaddr.sin_addr, optr, sizeof(u_long));
+	bcopy(&servaddr4.sin_addr, optr, sizeof(u_long));
 	optr += sizeof(u_long);
 	if (verbose) {
-		fprintf(stderr, "source route to %s\n", inet_ntoa(servaddr.sin_addr));
+		fprintf(stderr, "source route to %s\n",
+		    inet_ntoa(servaddr4.sin_addr));
 		fprintf(stderr, "source route size %d bytes\n", sroute_opt[1]);
 	}
 
