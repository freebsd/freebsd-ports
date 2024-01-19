--- netselect.c.orig	2010-10-26 23:08:55 UTC
+++ netselect.c
@@ -167,6 +167,7 @@ int main(int argc, char **argv)
     extern int optind;
     int hostcount, startcount, endcount = 0, sent_one, lag, min_lag = 100;
     int ch, seq, ttl, max_ttl = 30, num_score = 1;
+    int on = 1;
     int use_icmp = 0;
     unsigned int min_tries = 10;
     struct timeval now;
@@ -280,7 +281,12 @@ int main(int argc, char **argv)
     if (verbose >= 1)
 	fprintf(stderr, "Running netselect to choose %d out of %d address%s.\n",
 		num_score, numhosts, numhosts==1 ? "" : "es");
-    
+   
+   if (setsockopt(sndsock, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)) < 0) {
+        perror("IP_HDRINCL");
+	_exit(EXIT_FAILURE);
+   }
+
     /* keep going until most of the hosts have been finished */
     must_continue = numhosts;
     while (must_continue && must_continue >= numhosts/2)
@@ -774,7 +780,7 @@ static void send_probe(int seq, int ttl, OPacket *op, 
     ip->ip_off = 0;
     ip->ip_hl = sizeof(*ip) >> 2;
     ip->ip_p = IPPROTO_UDP;
-    ip->ip_len = 0; /* kernel fills this in */
+    ip->ip_len = sizeof(OPacket);
     ip->ip_ttl = ttl;
     ip->ip_v = IPVERSION;
     ip->ip_id = htons(ident + seq);
@@ -905,11 +911,7 @@ static HostData *wait_for_reply(HostData *hosts, int n
     time_t msec_used;
     HostData *host;
     
-#if !defined(__GLIBC__)
-    int fromlen = sizeof(from);
-#else				/* __GLIBC__ */
     socklen_t fromlen = sizeof(from);
-#endif				/* __GLIBC__ */
 
     FD_ZERO(&fds);
     FD_SET(sock, &fds);
