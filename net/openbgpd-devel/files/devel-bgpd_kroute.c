--- bgpd/kroute.c.orig	23 Feb 2006 15:25:18 -0000	1.144
+++ bgpd/kroute.c	16 Mar 2006 18:09:15 -0000
@@ -1723,7 +1723,9 @@ send_rtmsg(int fd, int action, struct kr
 		struct sockaddr_in	prefix;
 		struct sockaddr_in	nexthop;
 		struct sockaddr_in	mask;
+#if 0
 		struct sockaddr_rtlabel	label;
+#endif
 	} r;
 
 	if (kr_state.fib_sync == 0)
@@ -1756,9 +1758,11 @@ send_rtmsg(int fd, int action, struct kr
 	r.mask.sin_family = AF_INET;
 	r.mask.sin_addr.s_addr = htonl(prefixlen2mask(kroute->prefixlen));
 
+#if 0
 	r.label.sr_len = sizeof(r.label);
 	strlcpy(r.label.sr_label, rtlabel_id2name(kroute->labelid),
 	    sizeof(r.label.sr_label));
+#endif
 
 retry:
 	if (write(fd, &r, sizeof(r)) == -1) {
@@ -1799,7 +1803,9 @@ send_rt6msg(int fd, int action, struct k
 		struct sockaddr_in6	prefix;
 		struct sockaddr_in6	nexthop;
 		struct sockaddr_in6	mask;
+#if 0
 		struct sockaddr_rtlabel	label;
+#endif
 	} r;
 
 	if (kr_state.fib_sync == 0)
@@ -1832,9 +1838,11 @@ send_rt6msg(int fd, int action, struct k
 	memcpy(&r.mask.sin6_addr, prefixlen2mask6(kroute->prefixlen),
 	    sizeof(struct in6_addr));
 
+#if 0
 	r.label.sr_len = sizeof(r.label);
 	strlcpy(r.label.sr_label, rtlabel_id2name(kroute->labelid),
 	    sizeof(r.label.sr_label));
+#endif
 
 retry:
 	if (write(fd, &r, sizeof(r)) == -1) {
