--- oRTP/src/rtpsession.c.orig	Thu Mar 10 01:34:59 2005
+++ oRTP/src/rtpsession.c	Wed Mar 23 15:27:20 2005
@@ -377,16 +377,22 @@
 		    close_socket (session->rtp.socket);
 		    continue;
 		  }
-#ifndef __hpux
+#if !defined(__hpux) && !defined(__FreeBSD__)
 		switch (res->ai_family)
 		  {
 		    case AF_INET:
 		      if (IN_MULTICAST(ntohl(((struct sockaddr_in *) res->ai_addr)->sin_addr.s_addr)))
 			{
+#if !defined(__FreeBSD__)
 		          struct ip_mreqn mreq;
+#else
+		          struct ip_mreq mreq;
+#endif
 			  mreq.imr_multiaddr.s_addr = ((struct sockaddr_in *) res->ai_addr)->sin_addr.s_addr;
 			  mreq.imr_address.s_addr = INADDR_ANY;
+#if !defined(__FreeBSD__)
 			  mreq.imr_ifindex = 0;
+#endif
 			  err = setsockopt(session->rtp.socket, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq));
 			  if (err < 0)
 			    {
@@ -454,16 +460,22 @@
 		    close_socket (session->rtcp.socket);
 		    continue;
 		  }
-#ifndef __hpux
+#if !defined(__hpux) && !defined(__FreeBSD__)
 		switch (res->ai_family)
 		  {
 		    case AF_INET:
 		      if (IN_MULTICAST(ntohl(((struct sockaddr_in *) res->ai_addr)->sin_addr.s_addr)))
 			{
+#if !defined(__FreeBSD__)
 		          struct ip_mreqn mreq;
+#else
+		          struct ip_mreq mreq;
+#endif
 			  mreq.imr_multiaddr.s_addr = ((struct sockaddr_in *) res->ai_addr)->sin_addr.s_addr;
 			  mreq.imr_address.s_addr = INADDR_ANY;
+#if !defined(__FreeBSD__)
 			  mreq.imr_ifindex = 0;
+#endif
 			  err = setsockopt(session->rtcp.socket, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq));
 			  if (err < 0)
 			    {
@@ -555,13 +567,19 @@
 		close_socket (session->rtcp.socket);
 		return -1;
 	}
-#ifndef __hpux
+#if !defined(__hpux) && !defined(__FreeBSD__)
 	if (IN_MULTICAST(ntohl(session->rtp.loc_addr.sin_addr.s_addr)))
 	  {
+#if !defined(__FreeBSD__)
 	    struct ip_mreqn mreq;
+#else
+	    struct ip_mreq mreq;
+#endif
 	    mreq.imr_multiaddr.s_addr = session->rtp.loc_addr.sin_addr.s_addr;
 	    mreq.imr_address.s_addr = INADDR_ANY;
+#if !defined(__FreeBSD__)
 	    mreq.imr_ifindex = 0;
+#endif
 	    err = setsockopt(session->rtp.socket, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq));
 	    if (err == 0)
 	      err = setsockopt(session->rtcp.socket, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq));
