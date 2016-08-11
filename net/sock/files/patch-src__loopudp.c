--- src/loopudp.c.orig	2010-05-28 00:03:25 UTC
+++ src/loopudp.c
@@ -21,17 +21,28 @@
 void
 loop_udp(int sockfd)
 {
-	int maxfdp1, nread, ntowrite, stdineof, clilen, servlen, flags;
+	int maxfdp1, nread, ntowrite, stdineof, clilen, flags;
+	socklen_t		servlen;
 	fd_set			rset;
-	struct sockaddr_in	cliaddr;		/* for UDP server */
-	struct sockaddr_in	servaddr;		/* for UDP client */
+	struct sockaddr_in	cliaddr4;	/* for IPv4 UDP server */
+	struct sockaddr_in6	cliaddr6;	/* for IPv6 UDP server */
+	/*
+	 * The original local variable servaddr, and later servaddr4 and
+	 * servaddr6, were not initialized before use.  Using the initialized
+	 * global sockaddr structs allows the sendto() code, below, to work
+	 * correctly.  This was a problem with the original IPv4 code, and
+	 * later the IPv6 code.
+	 */
+	//struct sockaddr_in	servaddr4;	/* for IPv4 UDP client */
+	//struct sockaddr_in6	servaddr6;	/* for IPv6 UDP client */
+	char			inaddr_buf[INET6_ADDRSTRLEN];
 	
-	struct iovec			iov[1];
-	struct msghdr			msg;
+	struct iovec		iov[1];
+	struct msghdr		msg;
 #ifdef	HAVE_MSGHDR_MSG_CONTROL	  	
 #ifdef	IP_RECVDSTADDR		/* 4.3BSD Reno and later */
 	static struct cmsghdr  *cmptr = NULL;	/* malloc'ed */
-	struct in_addr			dstinaddr;		/* for UDP server */
+	struct in_addr		dstinaddr;	/* for UDP server */
 #define	CONTROLLEN	(sizeof(struct cmsghdr) + sizeof(struct in_addr))
 #endif	/* IP_RECVDSTADDR */
 	
@@ -68,8 +79,10 @@ loop_udp(int sockfd)
 						err_sys("shutdown() error");
 					
 					FD_CLR(STDIN_FILENO, &rset);
-					stdineof = 1;	/* don't read stdin anymore */
-					continue;		/* back to select() */
+					/* don't read stdin anymore */
+					stdineof = 1;
+					/* back to select() */
+					continue;
 				}
 				break;		/* default: stdin EOF -> done */
 			}
@@ -77,23 +90,43 @@ loop_udp(int sockfd)
 			if (crlf) {
 				ntowrite = crlf_add(wbuf, writelen, rbuf, nread);
 				if (connectudp) {
-					if (write(sockfd, wbuf, ntowrite) != ntowrite)
+					if (write(sockfd, wbuf, ntowrite) !=
+					    ntowrite) {
 						err_sys("write error");
+					}
 				} else {
-					if (sendto(sockfd, wbuf, ntowrite, 0,
-						   (struct sockaddr *) &servaddr, sizeof(servaddr))
-					    != ntowrite)
-						err_sys("sendto error");
+					if (af_46 == AF_INET) {
+						if (sendto(sockfd, wbuf, ntowrite, 0,
+						    (struct sockaddr *)&servaddr4,
+						    sizeof(servaddr4)) != ntowrite) {
+							err_sys("sendto error");
+						}
+					} else {
+						if (sendto(sockfd, wbuf, ntowrite, 0,
+						    (struct sockaddr *)&servaddr6,
+						    sizeof(servaddr6)) != ntowrite) {
+							err_sys("sendto error");
+						}
+					}
 				}
 			} else {
 				if (connectudp) {
 					if (write(sockfd, rbuf, nread) != nread)
 						err_sys("write error");
 				} else {
-					if (sendto(sockfd, rbuf, nread, 0,
-						   (struct sockaddr *) &servaddr, sizeof(servaddr))
-					    != nread)
-						err_sys("sendto error");
+					if (af_46 == AF_INET) {
+						if (sendto(sockfd, rbuf, nread, 0,
+						    (struct sockaddr *)&servaddr4,
+						    sizeof(servaddr4)) != nread) {
+							err_sys("sendto error");
+						}
+					} else {
+						if (sendto(sockfd, rbuf, nread, 0,
+						    (struct sockaddr *)&servaddr6,
+						    sizeof(servaddr6)) != nread) {
+							err_sys("sendto error");
+						}
+					}
 				}
 			}
 		}
@@ -101,35 +134,54 @@ loop_udp(int sockfd)
 		if (FD_ISSET(sockfd, &rset)) {
 			/* data to read from socket */
 			if (server) {
-				clilen = sizeof(cliaddr);
-#ifndef	MSG_TRUNC	/* vanilla BSD sockets */
+				if (af_46 == AF_INET) {
+					clilen = sizeof(cliaddr4);
+				} else {
+					clilen = sizeof(cliaddr6);
+				}
+
+#ifndef	MSG_TRUNC /* vanilla BSD sockets */
+
+				/* Fixme:  Not ported for IPv6 */
+				/* Not compiled in for FreeBSD 8.4 */
 				nread = recvfrom(sockfd, rbuf, readlen, 0,
-						 (struct sockaddr *) &cliaddr, &clilen);
-	      
+				    (struct sockaddr *) &cliaddr4, &clilen);
+
 #else	/* 4.3BSD Reno and later; use recvmsg() to get at MSG_TRUNC flag */
-	      /* Also lets us get at control information (destination address) */
-				
+	/* Also lets us get at control information (destination address) */
+
+				/* FreeBSD 8.4 */
 				iov[0].iov_base = rbuf;
 				iov[0].iov_len  = readlen;
-				msg.msg_iov          = iov;
-				msg.msg_iovlen       = 1;
-				msg.msg_name         = (caddr_t) &cliaddr;
-				msg.msg_namelen      = clilen;
-				
+				msg.msg_iov     = iov;
+				msg.msg_iovlen  = 1;
+				if (af_46 == AF_INET) {
+					msg.msg_name = (caddr_t) &cliaddr4;
+				} else {
+					msg.msg_name = (caddr_t) &cliaddr6;
+				}
+				msg.msg_namelen = clilen;
+
 #ifdef	HAVE_MSGHDR_MSG_CONTROL
 #ifdef	IP_RECVDSTADDR
+				/* FreeBSD 8.4 */
 				if (cmptr == NULL && (cmptr = malloc(CONTROLLEN)) == NULL)
 					err_sys("malloc error for control buffer");
 
-				msg.msg_control      = (caddr_t) cmptr;	/* for dest address */
+				/* for dest address */
+				msg.msg_control      = (caddr_t) cmptr;
 				msg.msg_controllen   = CONTROLLEN;
 #else
-				msg.msg_control      = (caddr_t) 0;	/* no ancillary data */
+				/* Not used for FreeBSD 8.4 */
+				/* no ancillary data */
+				msg.msg_control      = (caddr_t) 0;
 				msg.msg_controllen   = 0;
 #endif	/* IP_RECVDSTADDR */
 #endif
 #ifdef HAVE_MSGHDR_MSG_FLAGS
-				msg.msg_flags        = 0;			/* flags returned here */
+				/* FreeBSD 8.4 */
+				/* flags returned here */
+				msg.msg_flags        = 0;
 #endif				
 				nread = recvmsg(sockfd, &msg, 0);
 #endif	/* MSG_TRUNC */
@@ -137,22 +189,39 @@ loop_udp(int sockfd)
 					err_sys("datagram receive error");
 				
 				if (verbose) {
-					printf("from %s", INET_NTOA(cliaddr.sin_addr));
+					if (af_46 == AF_INET) {
+						printf("from %s",
+						    INET_NTOA(cliaddr4.sin_addr));
+					} else {
+			                        inet_ntop(AF_INET6,
+						    &cliaddr6.sin6_addr.
+						    __u6_addr.__u6_addr8,
+						    inaddr_buf,
+						    sizeof(inaddr_buf));
+						printf("from %s", inaddr_buf);
+					}
 #ifdef	HAVE_MSGHDR_MSG_CONTROL
 #ifdef	IP_RECVDSTADDR
+					/*
+					 * Fixme:  not ported for IPv6
+					 * Fixme:  recvdstaddr fails (earlier,
+					 *   in setsockopt()) for IPv6 under
+					 *   FreeBSD 8.4
+					 */
 					if (recvdstaddr) {
 						if (cmptr->cmsg_len != CONTROLLEN)
 							err_quit("control length (%d) != %d",
-								 cmptr->cmsg_len, CONTROLLEN);
+							    cmptr->cmsg_len, CONTROLLEN);
 						if (cmptr->cmsg_level != IPPROTO_IP)
 							err_quit("control level != IPPROTO_IP");
 						if (cmptr->cmsg_type != IP_RECVDSTADDR)
 							err_quit("control type != IP_RECVDSTADDR");
 						bcopy(CMSG_DATA(cmptr), &dstinaddr,
-						      sizeof(struct in_addr));
+						    sizeof(struct in_addr));
 						bzero(cmptr, CONTROLLEN);
 						
-						printf(", to %s", INET_NTOA(dstinaddr));
+						printf(", to %s",
+						    INET_NTOA(dstinaddr));
 					}
 #endif	/* IP_RECVDSTADDR */
 #endif	/* HAVE_MSGHDR_MSG_CONTROL */
@@ -178,15 +247,37 @@ loop_udp(int sockfd)
 				}
 	      
 			} else {
-				/* Must use recvfrom() for unconnected UDP client */
-				servlen = sizeof(servaddr);
-				nread = recvfrom(sockfd, rbuf, readlen, 0,
-						 (struct sockaddr *) &servaddr, &servlen);
-				if (nread < 0)
+				/*
+				 * Must use recvfrom() for unconnected
+				 * UDP client
+				 */
+				/* Fixme:  not tested on FreeBSD 8.4 */
+				if (af_46 == AF_INET) {
+					servlen = sizeof(servaddr4);
+					nread = recvfrom(sockfd, rbuf, readlen,
+					    0, (struct sockaddr *)&servaddr4,
+					    &servlen);
+				} else {
+					servlen = sizeof(servaddr6);
+					nread = recvfrom(sockfd, rbuf, readlen,
+					    0, (struct sockaddr *)&servaddr6,
+					    &servlen);
+				}
+				if (nread < 0) {
 					err_sys("datagram recvfrom() error");
-				
+				}
 				if (verbose) {
-					printf("from %s", INET_NTOA(servaddr.sin_addr));
+					if (af_46 == AF_INET) {
+						printf("from %s",
+						    INET_NTOA(servaddr4.sin_addr));
+					} else {
+			                        inet_ntop(AF_INET6,
+						    &servaddr6.sin6_addr.
+						    __u6_addr.__u6_addr8,
+						    inaddr_buf,
+						    sizeof(inaddr_buf));
+						printf("from %s", inaddr_buf);
+					}
 					printf(": ");
 					fflush(stdout);
 				}
