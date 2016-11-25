--- res/res_rtp_asterisk.c.orig	2016-11-23 15:26:01 UTC
+++ res/res_rtp_asterisk.c
@@ -2638,6 +2638,9 @@ static int ast_rtp_new(struct ast_rtp_in
 {
 	struct ast_rtp *rtp = NULL;
 	int x, startplace;
+#if defined(__FreeBSD__)
+	int portretryipv4 = 1;
+#endif
 
 	/* Create a new RTP structure to hold all of our data */
 	if (!(rtp = ast_calloc(1, sizeof(*rtp)))) {
@@ -2658,10 +2661,20 @@ static int ast_rtp_new(struct ast_rtp_in
 	}
 
 	/* Create a new socket for us to listen on and use */
-	if ((rtp->s =
-	     create_new_socket("RTP",
-			       ast_sockaddr_is_ipv4(addr) ? AF_INET  :
-			       ast_sockaddr_is_ipv6(addr) ? AF_INET6 : -1)) < 0) {
+#if defined(__FreeBSD__)
+	rtp->s = create_new_socket("RTP", AF_INET6);
+	if (rtp->s < 0) {
+		/* create correct addr structure for AF_INET */
+		ast_sockaddr_parse(addr, "0.0.0.0", 0);
+		rtp->s = create_new_socket("RTP", AF_INET);
+		portretryipv4 = 0;
+	}
+#else
+	rtp->s = create_new_socket("RTP",
+			ast_sockaddr_is_ipv4(addr) ? AF_INET  :
+			ast_sockaddr_is_ipv6(addr) ? AF_INET6 : -1);
+#endif
+	if (rtp->s < 0) {
 		ast_log(LOG_WARNING, "Failed to create a new socket for RTP instance '%p'\n", instance);
 		ast_free(rtp);
 		return -1;
@@ -2688,8 +2701,26 @@ static int ast_rtp_new(struct ast_rtp_in
 
 		/* See if we ran out of ports or if the bind actually failed because of something other than the address being in use */
 		if (x == startplace || (errno != EADDRINUSE && errno != EACCES)) {
+#if defined(__FreeBSD__)
+			/* Try again with IPv4 if not IPv6 port could be found */
+			if (portretryipv4 == 1) {
+				close(rtp->s);
+				ast_sockaddr_parse(addr, "0.0.0.0", 0);
+		                rtp->s = create_new_socket("RTP", AF_INET);
+				if (rtp->s >= 0) {
+					/* Reset the RTP port search parameters */
+					x = (rtpend == rtpstart) ? rtpstart : (ast_random() % (rtpend - rtpstart)) + rtpstart;
+					x = x & ~1;
+					startplace = x;
+					portretryipv4 = 0;
+					continue;
+				}
+			}
+#endif
 			ast_log(LOG_ERROR, "Oh dear... we couldn't allocate a port for RTP instance '%p'\n", instance);
-			close(rtp->s);
+			if (rtp->s >= 0) {
+				close(rtp->s);
+			}
 			ast_free(rtp);
 			return -1;
 		}
