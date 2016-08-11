--- src/cliopen.c.orig	2010-05-28 00:03:25 UTC
+++ src/cliopen.c
@@ -10,42 +10,107 @@
 
 #include "sock.h"
 
+/*
+ * Try to convert the host name as an IPv4 dotted-decimal number
+ * or an IPv6 address.
+ */
+int convert_host_address(char *host)
+{
+	struct in_addr		inaddr;
+	char			inaddr_buf[INET6_ADDRSTRLEN];
+
+	if (AF_INET == af_46) {
+		if (inet_pton(AF_INET, host, &inaddr) == 1) {
+			/* IPv4 dotted-decimal */
+			servaddr4.sin_addr = inaddr;
+
+			return (1);
+		}
+	} else {
+		if (inet_pton(AF_INET6, host, inaddr_buf) == 1) {
+			/* IPv6 address */
+			memcpy(&servaddr6.sin6_addr, inaddr_buf,
+			    sizeof(struct in6_addr));
+
+			return (1);
+		}
+	}
+
+	return (0);
+}
+
+/*
+ * Try to convert the host name as a host name string.
+ */
+int convert_host_name(char *host)
+{
+	struct hostent		*hp;
+
+	if (AF_INET == af_46) {
+		if ( (hp = gethostbyname2(host, AF_INET)) != NULL) {
+			/* IPv4 address */
+			memcpy(&servaddr4.sin_addr, hp->h_addr, hp->h_length);
+
+			return (1);
+		}
+	} else {
+		/*
+		 * Fixme:  This doesn't work on FreeBSD 8.4.
+		 * Only an IPv4 address is returned.
+		 * getaddrinfo() doesn't work either.
+		 */
+		if ( (hp = gethostbyname2(host, AF_INET6)) != NULL) {
+			/* IPv6 address */
+			memcpy(&servaddr6.sin6_addr, hp->h_addr, hp->h_length);
+
+			return (1);
+		}
+	}
+
+	return (0);
+}
+
 int cliopen(char *host, char *port)
 {
 	int			fd, i, on;
 	char			*protocol;
-	struct in_addr		inaddr;
+	char			inaddr_buf[INET6_ADDRSTRLEN];
 	struct servent		*sp;
-	struct hostent		*hp;
+	socklen_t		socklen;
 
 	protocol = udp ? "udp" : "tcp";
   
 	/* initialize socket address structure */
-	bzero(&servaddr, sizeof(servaddr));
-	servaddr.sin_family = AF_INET;
+	bzero(&servaddr4, sizeof(servaddr4));
+	servaddr4.sin_family = AF_INET;
+
+	bzero(&servaddr6, sizeof(servaddr6));
+	servaddr6.sin6_family = AF_INET6;
   
 	/* see if "port" is a service name or number */
 	if ( (i = atoi(port)) == 0) {
 		if ( (sp = getservbyname(port, protocol)) == NULL)
-			err_quit("getservbyname() error for: %s/%s", port, protocol);
-      
-		servaddr.sin_port = sp->s_port;
-	} else
-		servaddr.sin_port = htons(i);
+			err_quit("getservbyname() error for: %s/%s",
+			    port, protocol);
+		servaddr4.sin_port  = sp->s_port;
+		servaddr6.sin6_port = sp->s_port;
+	} else {
+		servaddr4.sin_port  = htons(i);
+		servaddr6.sin6_port = htons(i);
+	}
   
 	/*
-	 * First try to convert the host name as a dotted-decimal number.
-	 * Only if that fails do we call gethostbyname().
+	 * First try to convert the host name as an IPv4 dotted-decimal number
+	 * or an IPv6 address.  Only if that fails do we try to convert the
+	 * host name as a host name string.
 	 */
-  
-	if (inet_aton(host, &inaddr) == 1)
-		servaddr.sin_addr = inaddr;	/* it's dotted-decimal */
-	else if ( (hp = gethostbyname(host)) != NULL)
-		bcopy(hp->h_addr, &servaddr.sin_addr, hp->h_length);
-	else
-		err_quit("invalid hostname: %s", host);
+	if (convert_host_address(host) != 1) {
+		if (convert_host_name(host) != 1) {
+			err_quit("invalid hostname: %s", host);
+		}
+	}
 
-	if ( (fd = socket(AF_INET, udp ? SOCK_DGRAM : SOCK_STREAM, 0)) < 0)
+	if ( (fd = socket(af_46, udp ? SOCK_DGRAM : SOCK_STREAM, 0)) < 0)
 		err_sys("socket() error");
 
 	if (reuseaddr) {
@@ -71,21 +136,46 @@ int cliopen(char *host, char *port)
 	 * (and port) using -l option.  Allow localip[] to be set but bindport
 	 * to be 0.
 	 */
-	
 	if (bindport != 0 || localip[0] != 0 || udp) {
-		bzero(&cliaddr, sizeof(cliaddr));
-		cliaddr.sin_family      = AF_INET;
-		cliaddr.sin_port        = htons(bindport);   /* can be 0 */
-		if (localip[0] != 0) {
-			if (inet_aton(localip, &cliaddr.sin_addr) == 0)
-				err_quit("invalid IP address: %s", localip);
-		} else
-			cliaddr.sin_addr.s_addr = htonl(INADDR_ANY);	/* wildcard */
-		
-		if (bind(fd, (struct sockaddr *) &cliaddr, sizeof(cliaddr)) < 0)
-			err_sys("bind() error");
+		if (af_46 == AF_INET) {
+			bzero(&cliaddr4, sizeof(cliaddr4));
+			cliaddr4.sin_family      = AF_INET;
+			/* can be 0 */
+			cliaddr4.sin_port        = htons(bindport);
+			if (localip[0] != 0) {
+				if (inet_aton(localip, &cliaddr4.sin_addr) == 0)
+					err_quit("invalid IP address: %s",
+					    localip);
+			} else {
+				/* wildcard */
+				cliaddr4.sin_addr.s_addr = htonl(INADDR_ANY);
+			}
+			if (bind(fd, (struct sockaddr *) &cliaddr4,
+				    sizeof(cliaddr4)) < 0) {
+				err_sys("bind() error");
+			}
+		} else {
+			bzero(&cliaddr6, sizeof(cliaddr6));
+			cliaddr6.sin6_len    = sizeof(struct sockaddr_in6);
+			cliaddr6.sin6_family = AF_INET6;
+			/* can be 0 */
+			cliaddr6.sin6_port   = htons(bindport);
+
+			/* Fixme:  localip not implemented for IPv6 */
+			cliaddr6.sin6_addr = in6addr_any;
+
+			/* Fixme:  Want to set IPV6_BINDANY? */
+
+			if (bind(fd, (struct sockaddr *) &cliaddr6,
+				    sizeof(cliaddr6)) < 0) {
+				err_sys("bind() error");
+			}
+		}
 	}
-	
+
+	/* Fixme:  Does not work */
+	//join_mcast_client(fd, &cliaddr4, &cliaddr6, &servaddr4, &servaddr6);
+
 	/* Need to allocate buffers before connect(), since they can affect
 	 * TCP options (window scale, etc.).
 	 */
@@ -96,13 +186,21 @@ int cliopen(char *host, char *port)
 	/*
 	 * Connect to the server.  Required for TCP, optional for UDP.
 	 */
-	
 	if (udp == 0 || connectudp) {
 		for ( ; ; ) {
-			if (connect(fd, (struct sockaddr *) &servaddr, sizeof(servaddr))
-			    == 0)
+			if (AF_INET == af_46) {
+				if (connect(fd, (struct sockaddr *) &servaddr4,
+				    sizeof(servaddr4)) == 0)
 				break;		/* all OK */
-			if (errno == EINTR)		/* can happen with SIGIO */
+			} else {
+				servaddr6.sin6_len =
+				    sizeof(struct sockaddr_in6);
+				servaddr6.sin6_family = AF_INET6;
+				if (connect(fd, (struct sockaddr *) &servaddr6,
+				    sizeof(servaddr6)) == 0)
+				break;		/* all OK */
+			}
+			if (errno == EINTR)	/* can happen with SIGIO */
 				continue;
 			if (errno == EISCONN)	/* can happen with SIGIO */
 				break;
@@ -114,16 +212,38 @@ int cliopen(char *host, char *port)
 		/* Call getsockname() to find local address bound to socket:
 		   TCP ephemeral port was assigned by connect() or bind();
 		   UDP ephemeral port was assigned by bind(). */
-		i = sizeof(cliaddr);
-		if (getsockname(fd, (struct sockaddr *) &cliaddr, &i) < 0)
-			err_sys("getsockname() error");
-		
-		/* Can't do one fprintf() since inet_ntoa() stores
-		   the result in a static location. */
-		fprintf(stderr, "connected on %s.%d ",
-			INET_NTOA(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
-		fprintf(stderr, "to %s.%d\n",
-			INET_NTOA(servaddr.sin_addr), ntohs(servaddr.sin_port));
+		if (AF_INET == af_46) {
+			socklen = sizeof(cliaddr4);
+			if (getsockname(fd,
+			    (struct sockaddr *) &cliaddr4, &socklen) < 0) {
+				err_sys("getsockname() error");
+			}
+			/* Can't do one fprintf() since inet_ntoa() stores
+			   the result in a static location. */
+			fprintf(stderr, "connected on %s.%d ",
+			    INET_NTOA(cliaddr4.sin_addr),
+			    ntohs(cliaddr4.sin_port));
+			fprintf(stderr, "to %s.%d\n",
+			    INET_NTOA(servaddr4.sin_addr),
+			    ntohs(servaddr4.sin_port));
+		} else {
+			socklen = sizeof(cliaddr6);
+			if (getsockname(fd,
+			    (struct sockaddr *) &cliaddr6, &socklen) < 0) {
+				err_sys("getsockname() error");
+			}
+
+			inet_ntop(AF_INET6,
+			    &cliaddr6.sin6_addr.__u6_addr.__u6_addr8,
+			    inaddr_buf, sizeof(inaddr_buf));
+			fprintf(stderr, "connected on %s.%d ",
+			    inaddr_buf, ntohs(cliaddr6.sin6_port));
+			inet_ntop(AF_INET6,
+			    &servaddr6.sin6_addr.__u6_addr.__u6_addr8,
+			    inaddr_buf, sizeof(inaddr_buf));
+			fprintf(stderr, "to %s.%d\n",
+			    inaddr_buf, ntohs(servaddr6.sin6_port));
+		}
 	}
 	
 	sockopts(fd, 1);	/* some options get set after connect() */
