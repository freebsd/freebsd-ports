--- bgpd/kroute.c	3 Aug 2006 22:40:25 -0000	1.147
+++ bgpd/kroute.c	8 Feb 2007 10:31:16 -0000
@@ -1732,7 +1732,9 @@ send_rtmsg(int fd, int action, struct kr
 		struct sockaddr_in	prefix;
 		struct sockaddr_in	nexthop;
 		struct sockaddr_in	mask;
+#if 0
 		struct sockaddr_rtlabel	label;
+#endif
 	} r;
 
 	if (kr_state.fib_sync == 0)
@@ -1765,9 +1767,11 @@ send_rtmsg(int fd, int action, struct kr
 	r.mask.sin_family = AF_INET;
 	r.mask.sin_addr.s_addr = htonl(prefixlen2mask(kroute->prefixlen));
 
+#if 0
 	r.label.sr_len = sizeof(r.label);
 	strlcpy(r.label.sr_label, rtlabel_id2name(kroute->labelid),
 	    sizeof(r.label.sr_label));
+#endif
 
 retry:
 	if (write(fd, &r, sizeof(r)) == -1) {
@@ -1808,7 +1812,9 @@ send_rt6msg(int fd, int action, struct k
 		struct sockaddr_in6	prefix;
 		struct sockaddr_in6	nexthop;
 		struct sockaddr_in6	mask;
+#if 0
 		struct sockaddr_rtlabel	label;
+#endif
 	} r;
 
 	if (kr_state.fib_sync == 0)
@@ -1841,9 +1847,11 @@ send_rt6msg(int fd, int action, struct k
 	memcpy(&r.mask.sin6_addr, prefixlen2mask6(kroute->prefixlen),
 	    sizeof(struct in6_addr));
 
+#if 0
 	r.label.sr_len = sizeof(r.label);
 	strlcpy(r.label.sr_label, rtlabel_id2name(kroute->labelid),
 	    sizeof(r.label.sr_label));
+#endif
 
 retry:
 	if (write(fd, &r, sizeof(r)) == -1) {
Index: pfkey_compat.c
===================================================================
RCS file: pfkey_compat.c
diff -N pfkey_compat.c
