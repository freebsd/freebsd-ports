--- bgpd/kroute.c.orig	2009-01-16 23:03:20.000000000 +0900
+++ bgpd/kroute.c	2009-06-22 14:53:15.000000000 +0900
@@ -1747,7 +1747,9 @@
 	struct sockaddr_in	prefix;
 	struct sockaddr_in	nexthop;
 	struct sockaddr_in	mask;
+#if !defined(__FreeBSD__) /* FreeBSD has no route labeling. */
 	struct sockaddr_rtlabel	label;
+#endif /* !defined(__FreeBSD__) */
 	int			iovcnt = 0;
 
 	if (kr_state.fib_sync == 0)
@@ -1757,9 +1759,13 @@
 	bzero(&hdr, sizeof(hdr));
 	hdr.rtm_version = RTM_VERSION;
 	hdr.rtm_type = action;
+#if !defined(__FreeBSD__) /* XXX: FreeBSD has no multiple routing tables */
 	hdr.rtm_tableid = kr_state.rtableid;
+#endif /* !defined(__FreeBSD__) */
 	hdr.rtm_flags = RTF_PROTO1;
+#if !defined(__FreeBSD__) /* XXX: FreeBSD has no rtm_priority */
 	hdr.rtm_priority = RTP_BGP;
+#endif /* !defined(__FreeBSD__) */
 	if (kroute->flags & F_BLACKHOLE)
 		hdr.rtm_flags |= RTF_BLACKHOLE;
 	if (kroute->flags & F_REJECT)
@@ -1809,6 +1815,7 @@
 	iov[iovcnt++].iov_len = sizeof(mask);
 
 	if (kroute->labelid) {
+#if !defined(__FreeBSD__) /* FreeBSD has no route labeling. */
 		bzero(&label, sizeof(label));
 		label.sr_len = sizeof(label);
 		strlcpy(label.sr_label, rtlabel_id2name(kroute->labelid),
@@ -1819,6 +1826,7 @@
 		/* adjust iovec */
 		iov[iovcnt].iov_base = &label;
 		iov[iovcnt++].iov_len = sizeof(label);
+#endif /* !defined(__FreeBSD__) */
 	}
 
 retry:
@@ -1860,7 +1868,9 @@
 	struct sockaddr_in6	prefix;
 	struct sockaddr_in6	nexthop;
 	struct sockaddr_in6	mask;
+#if !defined(__FreeBSD__) /* FreeBSD has no route labeling. */
 	struct sockaddr_rtlabel	label;
+#endif /* !defined(__FreeBSD__) */
 	int			iovcnt = 0;
 
 	if (kr_state.fib_sync == 0)
@@ -1870,7 +1880,9 @@
 	bzero(&hdr, sizeof(hdr));
 	hdr.rtm_version = RTM_VERSION;
 	hdr.rtm_type = action;
+#if !defined(__FreeBSD__) /* XXX: FreeBSD has no multiple routing tables */ 
 	hdr.rtm_tableid = kr_state.rtableid;
+#endif /* !defined(__FreeBSD__) */
 	hdr.rtm_flags = RTF_PROTO1;
 	if (kroute->flags & F_BLACKHOLE)
 		hdr.rtm_flags |= RTF_BLACKHOLE;
@@ -1924,6 +1936,7 @@
 	iov[iovcnt++].iov_len = sizeof(mask);
 
 	if (kroute->labelid) {
+#if !defined(__FreeBSD__) /* FreeBSD has no route labeling. */
 		bzero(&label, sizeof(label));
 		label.sr_len = sizeof(label);
 		strlcpy(label.sr_label, rtlabel_id2name(kroute->labelid),
@@ -1934,6 +1947,7 @@
 		/* adjust iovec */
 		iov[iovcnt].iov_base = &label;
 		iov[iovcnt++].iov_len = sizeof(label);
+#endif /* !defined(__FreeBSD__) */
 	}
 
 retry:
@@ -1970,8 +1984,8 @@
 int
 fetchtable(u_int rtableid, int connected_only)
 {
-	size_t			 len;
-	int			 mib[7];
+	size_t			len;
+	int		 	mib[6];
 	char			*buf, *next, *lim;
 	struct rt_msghdr	*rtm;
 	struct sockaddr		*sa, *gw, *rti_info[RTAX_MAX];
@@ -1986,9 +2000,8 @@
 	mib[3] = 0;
 	mib[4] = NET_RT_DUMP;
 	mib[5] = 0;
-	mib[6] = rtableid;
 
-	if (sysctl(mib, 7, NULL, &len, NULL, 0) == -1) {
+	if (sysctl(mib, 6, NULL, &len, NULL, 0) == -1) {
 		if (rtableid != 0 && errno == EINVAL)	/* table nonexistent */
 			return (0);
 		log_warn("sysctl");
@@ -1998,7 +2011,7 @@
 		log_warn("fetchtable");
 		return (-1);
 	}
-	if (sysctl(mib, 7, buf, &len, NULL, 0) == -1) {
+	if (sysctl(mib, 6, buf, &len, NULL, 0) == -1) {
 		log_warn("sysctl");
 		free(buf);
 		return (-1);
@@ -2252,12 +2265,14 @@
 				continue;
 
 			connected_only = 0;
+#if !defined(__FreeBSD__) /* XXX: FreeBSD has no multiple routing tables */ 
 			if (rtm->rtm_tableid != kr_state.rtableid) {
 				if (rtm->rtm_tableid == 0)
 					connected_only = 1;
 				else
 					continue;
 			}
+#endif /* !defined(__FreeBSD__) */
 
 			if (dispatch_rtmsg_addr(rtm, rti_info,
 			    connected_only) == -1)
