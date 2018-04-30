--- xmit/get_tcp_conn.c.orig	2018-04-20 08:58:07 UTC
+++ xmit/get_tcp_conn.c
@@ -33,6 +33,7 @@ static const char * rcsid = "$Id: get_tc
 #ifndef	NONETDB
 #include <netdb.h>
 #endif	/* NONETDB */
+#include <syslog.h>
 
 extern	char	*Pname;
 #ifndef BSD_44
@@ -286,6 +287,50 @@ const char	*serv;
 	sp.sp_protocol	= (u_short)IPPROTO_TCP;
 #endif	/* OLDSOCKET */
 
+#ifndef PRE_IPv6
+	/* see "man getaddrinfo()" */
+	struct addrinfo hints, *addrs, *ai_p;
+	int r;
+
+	memset( &hints, 0, sizeof(hints) );
+	hints.ai_family = PF_UNSPEC;
+	hints.ai_socktype = SOCK_STREAM;
+	if ( (r = getaddrinfo( host, "nntp", &hints, &addrs )) != 0 )
+	{ 
+	    fprintf( stderr, "getaddrinfo(%s/nntp): %s", host, 
+			gai_strerror(r));
+	    return(NOHOST);
+	}
+	sock=-1;
+	for( ai_p = addrs; ai_p != NULL; ai_p = ai_p->ai_next )
+	{
+	    sock = socket( ai_p->ai_family, ai_p->ai_socktype, 
+                           ai_p->ai_protocol);
+	    if ( sock < 0 ) {continue;}
+	    if ( connect( sock, ai_p->ai_addr, ai_p->ai_addrlen ) < 0 )
+	    {
+		fprintf( stderr, "connect() failed: %s", strerror(errno));
+		close(sock); 
+		sock=-1;
+		continue;
+	    }
+	    if ( ai_p->ai_family == AF_INET6 )
+	    {
+		char addrbuf[100];
+		inet_ntop( ai_p->ai_family, ai_p->ai_addr, 
+                           addrbuf, sizeof(addrbuf) );
+		syslog(LOG_INFO, "IPv6 connect to %s (%s) - yeah!",
+			 host, addrbuf );
+	    }
+	    break;
+	}
+	freeaddrinfo(addrs);
+	if ( sock < 0 ) { return(FAIL); }
+
+	/* TODO: keepalives! */
+	return(sock);
+
+#else /*PRE_IPv6*/
 	if ((addrlist = name_to_address(host)) == (struct in_addr **)NULL) {
 		return(NOHOST);
 	}
@@ -330,4 +375,5 @@ const char	*serv;
 								    }
 	}
 	return(FAIL);
+#endif /* PRE_IPv6 */
 }
