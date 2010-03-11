This patch works around an order problem with dns servers.
If you have more then one milter, it is easy to do load
balancing by doing dns-round robin:

'X' marks the IP which gets the job.

Here's an example:

Case 1: 
-------

nslookup scan.filter

Address: 192.168.0.1 X 
Address: 192.168.0.2
Address: 192.168.0.3

Case 2:
-------

nslookup scan.filter

Address: 192.168.0.2 X
Address: 192.168.0.3
Address: 192.168.0.1

Case 3:
-------

nslookup scan.filter

Address: 192.168.0.3 X
Address: 192.168.0.1
Address: 192.168.0.2

As you see, we have three milter servers defined
for scan.filter. As long as all three servers are
working fine, there is no problem at all. All milters
get 33,3% of the work jobs.

But what happens if, for example, the server with the
IP 192.168.0.2 has crashed, or is out of service ?

Case 1: 
-------

nslookup scan.filter

Address: 192.168.0.1 X
Address: 192.168.0.2 Crashed
Address: 192.168.0.3

Case 2:
-------

nslookup scan.filter

Address: 192.168.0.2 Crashed
Address: 192.168.0.3 X
Address: 192.168.0.1

Case 3:
-------

nslookup scan.filter

Address: 192.168.0.3 X
Address: 192.168.0.1
Address: 192.168.0.2 Crashed

Now we have 33% of the jobs served to 192.168.0.1, and
66% of the jobs are given to 192.168.0.3. This is bad.

This patch randomizes the answer of the dns server, and
doesn't keep the order of the answer if there is any.

--- sendmail/milter.c.orig	Mon May 28 08:58:49 2007
+++ sendmail/milter.c	Mon May 28 09:03:17 2007
@@ -649,6 +649,10 @@
 	SOCKADDR_LEN_T addrlen = 0;
 	int addrno = 0;
 	int save_errno;
+	int tryaddr, countaddr;
+	int *hostlist;
+	int *tmphostlist;
+	char *tmpaddr;
 	char *p;
 	char *colon;
 	char *at;
@@ -972,12 +976,50 @@
 				return -1;
 			}
 			addr.sa.sa_family = hp->h_addrtype;
+ 
+ 			/* Count available hosts */
+ 			countaddr = 0;
+ 			while ((tmpaddr = hp->h_addr_list[countaddr]) != 0)
+ 				countaddr++;
+ 
+ 			hostlist = (int *) xalloc((countaddr+1) * sizeof(int)); 
+ 			tmphostlist = (int *) xalloc((countaddr+1) * sizeof(int));
+ 
+ 			if (countaddr < 2) {
+ 				/* Just use the first adress */
+ 				addrno = 0;
+ 			} else {
+ 				/* If we have more than two hosts use a random int value to
+ 				 * connect to one of those adresses. Some DNS are not able to
+ 				 * provide a working round robin DNS, they always give the
+ 				 * list in the same order.
+ 				 */
+ 				struct timeval t;
+ 				int i;
+ 
+ 				/* Init hostlist, we may need it later */
+ 				for (i=0; i < (countaddr+1); i++) {
+ 					if (i <= countaddr) {
+ 						hostlist[i] = i;
+ 					} else {
+ 						hostlist[i] = -1;
+ 					}
+ 					tmphostlist[i] = -1;
+ 				}
+ 
+ 				/* Get a random value between zero and countaddr) */
+ 				gettimeofday(&t, NULL);
+ 				srandom(t.tv_usec);
+ 				addrno = (random() % (countaddr));
+ 				hostlist[addrno] = -1;
+ 			}
+
 			switch (hp->h_addrtype)
 			{
 #  if NETINET
 			  case AF_INET:
 				memmove(&addr.sin.sin_addr,
-					hp->h_addr, INADDRSZ);
+					hp->h_addr_list[addrno], INADDRSZ);
 				addr.sin.sin_port = port;
 				addrlen = sizeof(struct sockaddr_in);
 				addrno = 1;
@@ -987,7 +1029,7 @@
 #  if NETINET6
 			  case AF_INET6:
 				memmove(&addr.sin6.sin6_addr,
-					hp->h_addr, IN6ADDRSZ);
+					hp->h_addr_list[addrno], IN6ADDRSZ);
 				addr.sin6.sin6_port = port;
 				addrlen = sizeof(struct sockaddr_in6);
 				addrno = 1;
@@ -1010,6 +1052,8 @@
 				milter_error(m, e);
 #  if NETINET6
 				freehostent(hp);
+				free(hostlist);
+				free(tmphostlist);
 #  endif /* NETINET6 */
 				return -1;
 			}
@@ -1038,6 +1082,8 @@
 # if NETINET6
 		if (hp != NULL)
 			freehostent(hp);
+		free(hostlist);
+		free(tmphostlist);
 # endif /* NETINET6 */
 		return 0;
 	}
@@ -1054,6 +1100,8 @@
 # if NETINET6
 		if (hp != NULL)
 			freehostent(hp);
+		free(hostlist);
+		free(tmphostlist);
 # endif /* NETINET6 */
 		return -1;
 	}
@@ -1077,6 +1125,8 @@
 # if NETINET6
 			if (hp != NULL)
 				freehostent(hp);
+			free(hostlist);
+			free(tmphostlist);
 # endif /* NETINET6 */
 			return -1;
 		}
@@ -1114,14 +1164,47 @@
 		(void) close(sock);
 
 		/* try next address */
-		if (hp != NULL && hp->h_addr_list[addrno] != NULL)
+
+		if (countaddr > 1) {
+			int i, j;
+			struct timeval t;
+ 
+			/*
+			 * Get a list of adresses we have not tried yet
+			 * to connect to.
+			 */
+			j = 0;
+			countaddr--;
+			for (i=0; i <= countaddr ; i++) {
+				if (hostlist[i] != -1) {
+					tmphostlist[j] = hostlist[i];
+					j++;
+				}
+			}
+			/*
+			 * Get a random value between zero and countaddr
+			 */
+			gettimeofday(&t, NULL);
+			srandom(t.tv_usec);
+			tryaddr = (random() % (countaddr));
+			addrno = tmphostlist[tryaddr];
+			/*
+			 * Now we can invalidate the entry and restore
+			 * the hostlist.
+			 */
+			tmphostlist[tryaddr] = -1;
+			memcpy(hostlist,tmphostlist, sizeof hostlist);
+		} else
+			addrno++;
+
+		if (countaddr > 0 && hp != NULL && hp->h_addr_list[addrno] != NULL)
 		{
 			switch (addr.sa.sa_family)
 			{
 # if NETINET
 			  case AF_INET:
 				memmove(&addr.sin.sin_addr,
-					hp->h_addr_list[addrno++],
+					hp->h_addr_list[addrno],
 					INADDRSZ);
 				break;
 # endif /* NETINET */
@@ -1129,7 +1212,7 @@
 # if NETINET6
 			  case AF_INET6:
 				memmove(&addr.sin6.sin6_addr,
-					hp->h_addr_list[addrno++],
+					hp->h_addr_list[addrno],
 					IN6ADDRSZ);
 				break;
 # endif /* NETINET6 */
@@ -1147,6 +1230,8 @@
 				milter_error(m, e);
 # if NETINET6
 				freehostent(hp);
+				free(hostlist);
+				free(tmphostlist);
 # endif /* NETINET6 */
 				return -1;
 			}
@@ -1166,6 +1251,8 @@
 # if NETINET6
 		if (hp != NULL)
 			freehostent(hp);
+		free(hostlist);
+		free(tmphostlist);
 # endif /* NETINET6 */
 		return -1;
 	}
@@ -1176,6 +1263,10 @@
 		freehostent(hp);
 		hp = NULL;
 	}
+	if (hostlist)
+		free(hostlist);
+	if (tmphostlist)
+		free(tmphostlist);
 # endif /* NETINET6 */
 # if MILTER_NO_NAGLE && !defined(TCP_CORK)
 	{
