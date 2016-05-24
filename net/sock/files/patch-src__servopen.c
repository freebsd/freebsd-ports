--- src/servopen.c.orig	2010-05-28 00:03:25 UTC
+++ src/servopen.c
@@ -19,38 +19,67 @@
 int
 servopen(char *host, char *port)
 {
-	int					fd, newfd, i, on, pid;
-	char				*protocol;
+	int			fd, newfd, i, on, pid;
+	char			*protocol;
 	struct in_addr		inaddr;
 	struct servent		*sp;
+	socklen_t		len;
+	char			inaddr_buf[INET6_ADDRSTRLEN];
 
 	protocol = udp ? "udp" : "tcp";
 
-		/* Initialize the socket address structure */
-	bzero(&servaddr, sizeof(servaddr));
-	servaddr.sin_family      = AF_INET;
+	/* Initialize the socket address structure */
+	bzero(&servaddr4, sizeof(servaddr4));
+	servaddr4.sin_family  = AF_INET;
 
-		/* Caller normally wildcards the local Internet address, meaning
-		   a connection will be accepted on any connected interface.
-		   We only allow an IP address for the "host", not a name. */
-	if (host == NULL)
-		servaddr.sin_addr.s_addr = htonl(INADDR_ANY);		/* wildcard */
-	else {
-		if (inet_aton(host, &inaddr) == 0)
-			err_quit("invalid host name for server: %s", host);
-		servaddr.sin_addr = inaddr;
+	bzero(&servaddr6, sizeof(servaddr6));
+	servaddr6.sin6_family = AF_INET6;
+
+	/*
+	 * Caller normally wildcards the local Internet address, meaning
+	 * a connection will be accepted on any connected interface.
+	 * We only allow an IP address for the "host", not a name.
+	 */
+	if (host == NULL) {
+		if (AF_INET == af_46) {
+			/* wildcard */
+			servaddr4.sin_addr.s_addr = htonl(INADDR_ANY);
+		} else {
+			/* wildcard */
+			servaddr6.sin6_addr = in6addr_any;
+		}
+	} else {
+		if (AF_INET == af_46) {
+			if (inet_pton(AF_INET, host, &inaddr) == 0) {
+				err_quit("invalid host name for server: %s",
+				    host);
+			}
+			/* IPv4 address */
+			servaddr4.sin_addr = inaddr;
+		} else {
+			if (inet_pton(AF_INET6, host, inaddr_buf) == 0) {
+				err_quit("invalid host name for server: %s",
+				    host);
+			}
+			/* IPv6 address */
+			memcpy(&servaddr6.sin6_addr, inaddr_buf,
+			    sizeof(struct in6_addr));
+		}
 	}
 
-		/* See if "port" is a service name or number */
+	/* See if "port" is a service name or number */
 	if ( (i = atoi(port)) == 0) {
 		if ( (sp = getservbyname(port, protocol)) == NULL)
-			err_ret("getservbyname() error for: %s/%s", port, protocol);
-
-		servaddr.sin_port = sp->s_port;
-	} else
-		servaddr.sin_port = htons(i);
+			err_ret("getservbyname() error for: %s/%s", port,
+			    protocol);
+		servaddr4.sin_port = sp->s_port;
+		servaddr6.sin6_port = sp->s_port;
+	} else {
+		servaddr4.sin_port = htons(i);
+		servaddr6.sin6_port = htons(i);
+	}
 
-	if ( (fd = socket(AF_INET, udp ? SOCK_DGRAM : SOCK_STREAM, 0)) < 0)
+	if ( (fd = socket(af_46, udp ? SOCK_DGRAM : SOCK_STREAM, 0)) < 0)
 		err_sys("socket() error");
 
 	if (reuseaddr) {
@@ -67,28 +96,37 @@ servopen(char *host, char *port)
 	}
 #endif
 
-		/* Bind our well-known port so the client can connect to us. */
-	if (bind(fd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
-		err_sys("can't bind local address");
+	/* Bind our well-known port so the client can connect to us. */
+	if (AF_INET == af_46) {
+		if (bind(fd, (struct sockaddr *) &servaddr4,
+			    sizeof(servaddr4)) < 0) {
+			err_sys("can't bind local address");
+		}
+	} else {
+		if (bind(fd, (struct sockaddr *) &servaddr6,
+			    sizeof(servaddr6)) < 0) {
+			err_sys("can't bind local address");
+		}
+	}
 
-	join_mcast(fd, &servaddr);
+	join_mcast_server(fd, &servaddr4, &servaddr6);
 
 	if (udp) {
 		buffers(fd);
 
-		if (foreignip[0] != 0) {	/* connect to foreignip/port# */
-			bzero(&cliaddr, sizeof(cliaddr));
-			if (inet_aton(foreignip, &cliaddr.sin_addr) == 0)
+		/* Fixme:  Not ported for IPv6 */
+		if (foreignip[0] != 0) {    /* connect to foreignip/port# */
+			bzero(&cliaddr4, sizeof(cliaddr4));
+			if (inet_aton(foreignip, &cliaddr4.sin_addr) == 0)
 				err_quit("invalid IP address: %s", foreignip);
-			cliaddr.sin_family = AF_INET;
-			cliaddr.sin_port   = htons(foreignport);
-				/* connect() for datagram socket doesn't appear to allow
-				   wildcarding of either IP address or port number */
+			cliaddr4.sin_family = AF_INET;
+			cliaddr4.sin_port   = htons(foreignport);
+			/* connect() for datagram socket doesn't appear to allow
+			   wildcarding of either IP address or port number */
 
-			if (connect(fd, (struct sockaddr *) &cliaddr, sizeof(cliaddr))
-																		  < 0)
+			if (connect(fd, (struct sockaddr *) &cliaddr4,
+			    sizeof(cliaddr4)) < 0)
 				err_sys("connect() error");
-			
 		}
 
 		sockopts(fd, 1);
@@ -96,58 +134,108 @@ servopen(char *host, char *port)
 		return(fd);		/* nothing else to do */
 	}
 
-	buffers(fd);		/* may set receive buffer size; must do here to get
-						   correct window advertised on SYN */
+	buffers(fd);		/* may set receive buffer size; must do here to
+				   get correct window advertised on SYN */
 	sockopts(fd, 0);	/* only set some socket options for fd */
 
 	listen(fd, listenq);
 
-	if (pauselisten)
-		sleep_us(pauselisten*1000);		/* lets connection queue build up */
+	if (pauselisten) {
+		/* lets connection queue build up */
+		sleep_us(pauselisten*1000);
+	}
 
-	if (dofork)
-		TELL_WAIT();			/* initialize synchronization primitives */
+	if (dofork) {
+		/* initialize synchronization primitives */
+		TELL_WAIT();
+	}
 
 	for ( ; ; ) {
-		i = sizeof(cliaddr);
-		if ( (newfd = accept(fd, (struct sockaddr *) &cliaddr, &i)) < 0)
-			err_sys("accept() error");
+		if (AF_INET == af_46) {
+			len = sizeof(cliaddr4);
+			if ( (newfd = accept(fd, (struct sockaddr *) &cliaddr4,
+				    &len)) < 0) {
+				err_sys("accept() error");
+			}
+		} else {
+			len = sizeof(cliaddr6);
+			if ( (newfd = accept(fd, (struct sockaddr *) &cliaddr6,
+				    &len)) < 0) {
+				err_sys("accept() error");
+			}
+		}
 
 		if (dofork) {
 			if ( (pid = fork()) < 0)
 				err_sys("fork error");
 
 			if (pid > 0) {
-				close(newfd);	/* parent closes connected socket */
-				WAIT_CHILD();	/* wait for child to output to terminal */
-				continue;		/* and back to for(;;) for another accept() */
+				/* parent closes connected socket */
+				close(newfd);
+				/* wait for child to output to terminal */
+				WAIT_CHILD();
+				/* and back to for(;;) for another accept() */
+				continue;
 			} else {
-				close(fd);		/* child closes listening socket */
+				/* child closes listening socket */
+				close(fd);
 			}
 		}
 
-			/* child (or iterative server) continues here */
+		/* child (or iterative server) continues here */
 		if (verbose) {
-				/* Call getsockname() to find local address bound to socket:
-				   local internet address is now determined (if multihomed). */
-			i = sizeof(servaddr);
-			if (getsockname(newfd, (struct sockaddr *) &servaddr, &i) < 0)
-				err_sys("getsockname() error");
+			/*
+			 * Call getsockname() to find local address bound
+			 * to socket: local internet address is now
+			 * determined (if multihomed).
+			 */
+			if (AF_INET == af_46) {
+				len = sizeof(servaddr4);
+				if (getsockname(newfd,
+				    (struct sockaddr *)&servaddr4, &len) < 0) {
+					err_sys("getsockname() error");
+				}
 
-						/* Can't do one fprintf() since inet_ntoa() stores
-						   the result in a static location. */
-			fprintf(stderr, "connection on %s.%d ",
-					INET_NTOA(servaddr.sin_addr), ntohs(servaddr.sin_port));
-			fprintf(stderr, "from %s.%d\n",
-					INET_NTOA(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
+				/*
+				 * Can't do one fprintf() since inet_ntoa()
+				 * stores the result in a static location.
+				 */
+				fprintf(stderr, "connection on %s.%d ",
+				    INET_NTOA(servaddr4.sin_addr),
+				    ntohs(servaddr4.sin_port));
+				fprintf(stderr, "from %s.%d\n",
+				    INET_NTOA(cliaddr4.sin_addr),
+				    ntohs(cliaddr4.sin_port));
+			} else {
+				len = sizeof(servaddr6);
+				if (getsockname(newfd,
+				    (struct sockaddr *)&servaddr6, &len) < 0) {
+					err_sys("getsockname() error");
+				}
+				inet_ntop(AF_INET6,
+				    &servaddr6.sin6_addr.__u6_addr.__u6_addr8,
+				    inaddr_buf, sizeof(inaddr_buf));
+				fprintf(stderr, "connection on %s.%d ",
+				    inaddr_buf, ntohs(servaddr6.sin6_port));
+				inet_ntop(AF_INET6,
+				    &cliaddr6.sin6_addr.__u6_addr.__u6_addr8,
+				    inaddr_buf, sizeof(inaddr_buf));
+				fprintf(stderr, "from %s.%d\n",
+				    inaddr_buf, ntohs(cliaddr6.sin6_port));
+			}
 		}
 
-		buffers(newfd);		/* setsockopt() again, in case it didn't propagate
-							   from listening socket to connected socket */
-		sockopts(newfd, 1);	/* can set all socket options for this socket */
+		/* setsockopt() again, in case it didn't propagate
+		   from listening socket to connected socket */
+		buffers(newfd);
 
-		if (dofork)
-			TELL_PARENT(getppid());	/* tell parent we're done with terminal */
+		/* can set all socket options for this socket */
+		sockopts(newfd, 1);
+
+		if (dofork) {
+			/* tell parent we're done with terminal */
+			TELL_PARENT(getppid());
+		}
 
 		return(newfd);
 	}
