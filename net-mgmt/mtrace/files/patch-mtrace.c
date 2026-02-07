--- mtrace.c.orig	1998-12-04 04:48:19 UTC
+++ mtrace.c
@@ -147,8 +147,9 @@ static char rcsid[] =
 #ifdef SUNOS5
 #include <sys/systeminfo.h>
 #endif
+#include <inttypes.h>
+typedef uint32_t	u_int32;
 
-typedef unsigned int u_int32;	/* XXX */
 #include "mtrace.h"
 
 #define DEFAULT_TIMEOUT	3	/* How long to wait before retrying requests */
@@ -283,7 +284,7 @@ extern char *		sys_errlist[];
 #endif
 
 #define RECV_BUF_SIZE 8192
-char	*send_buf, *recv_buf;
+u_char	*send_buf, *recv_buf;
 int	igmp_socket;
 u_int32	allrtrs_group;
 char	router_alert[4];	     	/* Router Alert IP Option	    */
@@ -309,7 +310,7 @@ int ip_addlen = 0;		     	/* Workaround 
 #endif
 
 typedef int (*callback_t) __P((int, u_char *, int, struct igmp *, int,
-			struct sockaddr *, int *, struct timeval *));
+			struct sockaddr *, socklen_t *, struct timeval *));
 
 void			init_igmp __P((void));
 void			send_igmp __P((u_int32 src, u_int32 dst, int type,
@@ -380,10 +381,10 @@ init_igmp()
 {
     struct ip *ip;
 
-    recv_buf = (char *)malloc(RECV_BUF_SIZE);
+    recv_buf = (u_char *)malloc(RECV_BUF_SIZE);
     if (recv_buf == 0)
 	log(LOG_ERR, 0, "Out of memory allocating recv_buf!");
-    send_buf = (char *)malloc(RECV_BUF_SIZE);
+    send_buf = (u_char *)malloc(RECV_BUF_SIZE);
     if (send_buf == 0)
 	log(LOG_ERR, 0, "Out of memory allocating send_buf!");
 
@@ -1196,7 +1197,8 @@ send_recv(dst, type, code, tries, save, 
     u_int32 local, group;
     int ipdatalen, iphdrlen, igmpdatalen;
     int datalen;
-    int count, recvlen, socklen = sizeof(recvaddr);
+    int count, recvlen;
+    socklen_t socklen = sizeof(recvaddr);
     int len;
     int i;
 
@@ -1486,7 +1488,8 @@ passive_mode()
     struct sockaddr_in recvaddr;
     struct tm *now;
     char timebuf[32];
-    int socklen;
+    time_t tr_sec;
+    socklen_t socklen;
     int ipdatalen, iphdrlen, igmpdatalen;
     int len, recvlen;
     int qid;
@@ -1593,7 +1596,8 @@ passive_mode()
 	    }
 	}
 
-	now = localtime(&tr.tv_sec);
+	tr_sec = tr.tv_sec;
+	now = localtime(&tr_sec);
 	strftime(timebuf, sizeof(timebuf) - 1, "%b %e %k:%M:%S", now);
 	printf("Mtrace %s at %s",
 		len == 0 ? "query" :
@@ -1972,11 +1976,12 @@ stat_line(r, s, have_next, rst)
 	break;
 
       case NEITHER:
-	if (ghave != NEITHER)
+	if (ghave != NEITHER) {
 	    if (tunstats)
 		printf("                         ");
 	    else
 		printf("           ");
+	}
 
 	break;
     }
@@ -2027,17 +2032,21 @@ stat_line(r, s, have_next, rst)
 
 
     if (debug > 2) {
-	printf("\t\t\t\tv_in: %ld ", ntohl(s->tr_vifin));
-	printf("v_out: %ld ", ntohl(s->tr_vifout));
-	printf("pkts: %ld\n", ntohl(s->tr_pktcnt));
-	printf("\t\t\t\tv_in: %ld ", ntohl(r->tr_vifin));
-	printf("v_out: %ld ", ntohl(r->tr_vifout));
-	printf("pkts: %ld\n", ntohl(r->tr_pktcnt));
-	printf("\t\t\t\tv_in: %ld ",ntohl(s->tr_vifin)-ntohl(r->tr_vifin));
-	printf("v_out: %ld ", ntohl(s->tr_vifout) - ntohl(r->tr_vifout));
-	printf("pkts: %ld ", ntohl(s->tr_pktcnt) - ntohl(r->tr_pktcnt));
+	printf("\t\t\t\tv_in: %jd ", (uintmax_t)ntohl(s->tr_vifin));
+	printf("v_out: %jd ", (uintmax_t)ntohl(s->tr_vifout));
+	printf("pkts: %jd\n", (uintmax_t)ntohl(s->tr_pktcnt));
+	printf("\t\t\t\tv_in: %jd ", (uintmax_t)ntohl(r->tr_vifin));
+	printf("v_out: %jd ", (uintmax_t)ntohl(r->tr_vifout));
+	printf("pkts: %jd\n", (uintmax_t)ntohl(r->tr_pktcnt));
+	printf("\t\t\t\tv_in: %jd ",
+	    (uintmax_t)(ntohl(s->tr_vifin)-ntohl(r->tr_vifin)));
+	printf("v_out: %jd ",
+	    (uintmax_t)(ntohl(s->tr_vifout) - ntohl(r->tr_vifout)));
+	printf("pkts: %jd ",
+	    (uintmax_t)(ntohl(s->tr_pktcnt) - ntohl(r->tr_pktcnt)));
 	printf("time: %d\n", timediff);
-	printf("\t\t\t\treset: %x hoptime: %lx\n", *rst, ntohl(s->tr_qarr));
+	printf("\t\t\t\treset: %x hoptime: %lx\n", *rst,
+	    (u_long)ntohl(s->tr_qarr));
     }
 }
 
@@ -2148,8 +2157,10 @@ fixup_stats(base, prev, new, bugs)
 	if (debug > 2) {
     	    printf("\t\tip=%s, r=%d, res=%d\n", inet_fmt(b->tr_inaddr, s1), *r, res);
 	    if (res)
-		printf("\t\tbase=%ld, prev=%ld, new=%ld\n", ntohl(b->tr_pktcnt),
-			    ntohl(p->tr_pktcnt), ntohl(n->tr_pktcnt));
+		printf("\t\tbase=%jd, prev=%jd, new=%jd\n",
+		    (uintmax_t)ntohl(b->tr_pktcnt),
+			    (uintmax_t)ntohl(p->tr_pktcnt),
+		    (uintmax_t)ntohl(n->tr_pktcnt));
 	}
 	if (*r & BUG_RESET) {
 	    if (res || (*r & BUG_RESET2X)) {
@@ -2286,16 +2297,20 @@ print_stats(base, prev, new, bugs, names
 	printf("     v     ^\n");
     }
     if (debug > 2) {
-	printf("\t\t\t\tv_in: %ld ", ntohl(n->tr_vifin));
-	printf("v_out: %ld ", ntohl(n->tr_vifout));
-	printf("pkts: %ld\n", ntohl(n->tr_pktcnt));
-	printf("\t\t\t\tv_in: %ld ", ntohl(b->tr_vifin));
-	printf("v_out: %ld ", ntohl(b->tr_vifout));
-	printf("pkts: %ld\n", ntohl(b->tr_pktcnt));
-	printf("\t\t\t\tv_in: %ld ", ntohl(n->tr_vifin) - ntohl(b->tr_vifin));
-	printf("v_out: %ld ", ntohl(n->tr_vifout) - ntohl(b->tr_vifout));
-	printf("pkts: %ld\n", ntohl(n->tr_pktcnt) - ntohl(b->tr_pktcnt));
-	printf("\t\t\t\treset: %x hoptime: %lx\n", *r, ntohl(n->tr_qarr));
+	printf("\t\t\t\tv_in: %jd ", (uintmax_t)ntohl(n->tr_vifin));
+	printf("v_out: %jd ", (uintmax_t)ntohl(n->tr_vifout));
+	printf("pkts: %jd\n", (uintmax_t)ntohl(n->tr_pktcnt));
+	printf("\t\t\t\tv_in: %jd ", (uintmax_t)ntohl(b->tr_vifin));
+	printf("v_out: %jd ", (uintmax_t)ntohl(b->tr_vifout));
+	printf("pkts: %jd\n", (uintmax_t)ntohl(b->tr_pktcnt));
+	printf("\t\t\t\tv_in: %jd ",
+	    (uintmax_t)(ntohl(n->tr_vifin) - ntohl(b->tr_vifin)));
+	printf("v_out: %jd ",
+	    (uintmax_t)(ntohl(n->tr_vifout) - ntohl(b->tr_vifout)));
+	printf("pkts: %jd\n",
+	    (uintmax_t)(ntohl(n->tr_pktcnt) - ntohl(b->tr_pktcnt)));
+	printf("\t\t\t\treset: %x hoptime: %lx\n", *r,
+	    (u_long)ntohl(n->tr_qarr));
     }
 
     while (TRUE) {
@@ -2386,7 +2401,7 @@ char *argv[];
 {
     int udp;
     struct sockaddr_in addr;
-    int addrlen = sizeof(addr);
+    socklen_t addrlen = sizeof(addr);
     int recvlen;
     struct timeval tv;
     struct resp_buf *prev, *new;
@@ -2957,7 +2972,7 @@ continuehop:
 
     if (base.rtime == 0) {
 	printf("Timed out receiving responses\n");
-	if (IN_MULTICAST(ntohl(tdst)))
+	if (IN_MULTICAST(ntohl(tdst))) {
 	  if (tdst == query_cast)
 	    printf("Perhaps no local router has a route for source %s\n",
 		   inet_fmt(qsrc, s1));
@@ -2967,6 +2982,7 @@ or no router local to it has a route for
 or multicast at ttl %d doesn't reach its last-hop router for that source\n",
 		   inet_fmt(qdst, s2), inet_fmt(qgrp, s3), inet_fmt(qsrc, s1),
 		   qttl ? qttl : MULTICAST_TTL1);
+	}
 	exit(1);
     }
 
