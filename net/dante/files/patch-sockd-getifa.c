--- sockd/getifa.c.orig	2003-07-01 13:21:40.000000000 +0000
+++ sockd/getifa.c	2009-01-18 23:43:40.000000000 +0000
@@ -58,6 +58,9 @@
  * that will be selected by the OS to connect to that destination address.
  *==========================================================================*/
 #include	<net/route.h>           /* RTA_xxx constants */
+#if HAVE_ROUTEINFO_BSD
+#include	<net/if_dl.h>
+#endif /* HAVE_ROUTEINFO_BSD */
 #if HAVE_ROUTEINFO_LINUX
 #include	<asm/types.h>
 #include	<linux/netlink.h>
@@ -233,9 +236,11 @@
 	pid_t				pid;
 	struct rt_msghdr *rtm;
 	struct sockaddr *sa;
+	char *cp;
+	int i;
 	uid_t euid;
 	struct in_addr inaddr_none;
-	struct in_addr gwaddr;
+	struct sockaddr ifa;
 
 	inaddr_none.s_addr = htonl(INADDR_NONE);
 
@@ -256,85 +261,123 @@
 	}
 
 	/*===================================================================
-	 * Do until 2 consecutive RTM_GET return the same gateway address.
-	 * The first calls may return router addresses in RTA_GATEWAY and
-	 * those will not match any local external address.
+	 * Do a RTM_GET to look up the gateway for the address.
+	 * Extract the RTM_IFA from it, which is the source address used
+	 * on that interface.
+	 * The code is modeled after the code for route(8).
 	 *==================================================================*/
+	/*===========================================================
+	 * Build the necessary data structures to get routing info.
+	 * The structures are:
+	 *   rt_msghdr - Specifies RTM_GET for getting routing table
+	 *		info
+	 *   sockaddr - contains the destination address
+	 *   sockaddr_dl - necessary for unkown reasons.
+	 *==========================================================*/
+#define ROUNDUP(a) \
+	((a) > 0 ? (1 + (((a) - 1) | (sizeof(long) - 1))) : sizeof(long))
+#define ADVANCE(x, n) (x += ROUNDUP((n)->sa_len))
+
+
+	bzero(buf, sizeof(buf));
+	rtm					= (struct rt_msghdr *) buf;
+	rtm->rtm_version	= RTM_VERSION;
+	rtm->rtm_type		= RTM_GET;
+	rtm->rtm_flags		= RTF_UP | RTF_HOST | RTF_GATEWAY | RTF_STATIC;
+	rtm->rtm_addrs		= RTA_DST | RTA_IFA;
+	rtm->rtm_pid		= pid = getpid();
+	rtm->rtm_seq		= SEQ;
+
+	cp  = (char *) (rtm + 1);
+	sa = (struct sockaddr *) cp;
+	/* LINTED pointer casts may be troublesome */
+	TOIN(sa)->sin_family	= AF_INET;
+	/* LINTED pointer casts may be troublesome */
+	TOIN(sa)->sin_addr	= destaddr;
+	/* LINTED pointer casts may be troublesome */
+	TOIN(sa)->sin_port	= htons(0);
+	sa->sa_len = sizeof(struct sockaddr_in);
+	ADVANCE(cp, sa);
+	sa = (struct sockaddr *) cp;
+	/* add dummy link layer address */
+	sa->sa_family = AF_LINK;
+	sa->sa_len = sizeof(struct sockaddr_dl);
+	ADVANCE(cp, sa);
+	sa = (struct sockaddr *) cp;
+	rtm->rtm_addrs |= RTA_IFP;
+
+	rtm->rtm_msglen = cp - buf;
+
+	/*===========================================================
+	 * Send the request and get the response.
+	 *==========================================================*/
+	if (write(sockfd, rtm, (size_t)rtm->rtm_msglen) != rtm->rtm_msglen) {
+		swarn("%s: write() to AF_ROUTE failed", function);
+		close(sockfd);
+		return inaddr_none;
+	}
+
 	do {
-		/*===========================================================
-		 * Build the necessary data structures to get routing info.
-		 * The structures are:
-		 *   rt_msghdr - Specifies RTM_GET for getting routing table
-		 *		info
-		 *   sockaddr - contains the destination address
-		 *==========================================================*/
-
-		bzero(buf, sizeof(buf));
-		rtm					= (struct rt_msghdr *) buf;
-		rtm->rtm_msglen	= sizeof(struct rt_msghdr) + sizeof(struct sockaddr_in);
-		rtm->rtm_version	= RTM_VERSION;
-		rtm->rtm_type		= RTM_GET;
-		rtm->rtm_addrs		= RTA_DST;
-		rtm->rtm_pid		= pid = getpid();
-		rtm->rtm_seq		= SEQ;
-
-		sa							= (struct sockaddr *) (rtm + 1);
-		/* LINTED pointer casts may be troublesome */
-		TOIN(sa)->sin_family	= AF_INET;
-		/* LINTED pointer casts may be troublesome */
-		TOIN(sa)->sin_addr	= destaddr;
-		/* LINTED pointer casts may be troublesome */
-		TOIN(sa)->sin_port	= htons(0);
-
-		/*===========================================================
-		 * Send the request and get the response.
-		 *==========================================================*/
-		if (write(sockfd, rtm, (size_t)rtm->rtm_msglen) != rtm->rtm_msglen) {
-			swarn("%s: write() to AF_ROUTE failed", function);
+		if (read(sockfd, rtm, sizeof(buf)) == -1) {
+			swarn("%s: read from AF_ROUTE failed", function);
 			close(sockfd);
 			return inaddr_none;
 		}
+	} while (rtm->rtm_type != RTM_GET || rtm->rtm_seq != SEQ
+	|| rtm->rtm_pid != pid);
 
-		do {
-			if (read(sockfd, rtm, sizeof(buf)) == -1) {
-				swarn("%s: read from AF_ROUTE failed", function);
+	/*================================================================
+	 * Iterate over the address structure extracting only the relevant
+	 * addresses.
+	 *===============================================================*/
+	cp  = (char *) (rtm + 1);
+	sa = (struct sockaddr *) cp;
+
+	for (i=0; (i < RTAX_MAX) && (cp < buf + sizeof(buf)); i++) {
+		switch (i) {
+		case RTAX_GATEWAY:
+			if (!(rtm->rtm_addrs & RTA_GATEWAY)) {
+				slog(LOG_DEBUG, "%s: can't find gateway for %s, using defaultexternal",
+				function, inet_ntoa(destaddr));
 				close(sockfd);
-				return inaddr_none;
+				return getdefaultexternal();
 			}
-		} while (rtm->rtm_type != RTM_GET || rtm->rtm_seq != SEQ
-		|| rtm->rtm_pid != pid);
-
-		/*============================================================
-		 * Go straight to the RTA_GATEWAY entry for our info.
-		 *===========================================================*/
-		sa = (struct sockaddr *) (rtm + 1);
-
-		if (!(rtm->rtm_addrs & RTA_GATEWAY)
-		||  (sa += RTAX_GATEWAY) == NULL
-		||  TOIN(sa)->sin_family != AF_INET) {
-			slog(LOG_DEBUG, "%s: can't find gateway for %s, using defaultexternal",
-			function, inet_ntoa(destaddr));
-			close(sockfd);
-			return getdefaultexternal();
+			break;
+		case RTAX_IFA:
+			if (!(rtm->rtm_addrs & RTA_IFA)
+				||  TOIN(sa)->sin_family != AF_INET) {
+				slog(LOG_DEBUG, "%s: can't find ifa for %s, using defaultexternal",
+				function, inet_ntoa(destaddr));
+				close(sockfd);
+				return getdefaultexternal();
+			}
+			else {
+				memcpy((void*)&ifa, (void*)sa, sa->sa_len);
+			}
+			break;
+		}
+		if (rtm->rtm_addrs & (1<<i)) {
+			ADVANCE(cp, sa);
+			sa = (struct sockaddr *)cp;
 		}
+#undef ROUNDUP
+#undef ADVANCE
 
-		gwaddr.s_addr = destaddr.s_addr;
-		destaddr.s_addr = TOIN(sa)->sin_addr.s_addr;
-	} while (destaddr.s_addr != gwaddr.s_addr);
+	}
 
 	close(sockfd);
 
-	if (!isonexternal(sa)) {
+	if (!isonexternal(&ifa)) {
 		char a[MAXSOCKADDRSTRING];
 
 		swarnx("%s: address %s selected, but not set for external interface",
-		function, sockaddr2string(sa, a, sizeof(a)));
+		function, sockaddr2string(&ifa, a, sizeof(a)));
 
 		return getdefaultexternal();
 	}
 
 	/* LINTED pointer casts may be troublesome */
-	return TOIN(sa)->sin_addr;
+	return TOIN(&ifa)->sin_addr;
 }
 
 #else /* HAVE_ROUTEINFO_BSD */
@@ -393,7 +436,7 @@
 		struct sockaddr check;
 		int match = 0;
 
-		switch ((*sockscf.external.addrv).atype) {
+		switch (sockscf.external.addrv[i].atype) {
 			case SOCKS_ADDR_IFNAME: {
 				int ifi;
 
