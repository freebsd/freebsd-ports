--- bgpd/kroute.c.orig	2007-05-11 13:27:59.000000000 +0200
+++ bgpd/kroute.c	2009-04-23 05:14:47.000000000 +0200
@@ -1738,7 +1738,9 @@
 	struct sockaddr_in	prefix;
 	struct sockaddr_in	nexthop;
 	struct sockaddr_in	mask;
+#if !defined(__FreeBSD__) /* FreeBSD has no route labeling. */
 	struct sockaddr_rtlabel	label;
+#endif /* !defined(__FreeBSD__) */
 	int			iovcnt = 0;
 
 	if (kr_state.fib_sync == 0)
@@ -1748,7 +1750,9 @@
 	bzero(&hdr, sizeof(hdr));
 	hdr.rtm_version = RTM_VERSION;
 	hdr.rtm_type = action;
+#if !defined(__FreeBSD__) /* XXX: FreeBSD has no multiple routing tables */ 
 	hdr.rtm_tableid = kr_state.rtableid;
+#endif
 	hdr.rtm_flags = RTF_PROTO1;
 	if (kroute->flags & F_BLACKHOLE)
 		hdr.rtm_flags |= RTF_BLACKHOLE;
@@ -1799,6 +1803,7 @@
 	iov[iovcnt++].iov_len = sizeof(mask);
 
 	if (kroute->labelid) {
+#if !defined(__FreeBSD__) /* FreeBSD has no route labeling. */
 		bzero(&label, sizeof(label));
 		label.sr_len = sizeof(label);
 		strlcpy(label.sr_label, rtlabel_id2name(kroute->labelid),
@@ -1809,6 +1814,7 @@
 		/* adjust iovec */
 		iov[iovcnt].iov_base = &label;
 		iov[iovcnt++].iov_len = sizeof(label);
+#endif /* !defined(__FreeBSD__) */
 	}
 
 retry:
@@ -1850,7 +1856,9 @@
 	struct sockaddr_in6	prefix;
 	struct sockaddr_in6	nexthop;
 	struct sockaddr_in6	mask;
+#if !defined(__FreeBSD__) /* FreeBSD has no route labeling. */
 	struct sockaddr_rtlabel	label;
+#endif /* !defined(__FreeBSD__) */
 	int			iovcnt = 0;
 
 	if (kr_state.fib_sync == 0)
@@ -1860,7 +1868,9 @@
 	bzero(&hdr, sizeof(hdr));
 	hdr.rtm_version = RTM_VERSION;
 	hdr.rtm_type = action;
+#if !defined(__FreeBSD__) /* XXX: FreeBSD has no multiple routing tables */ 
 	hdr.rtm_tableid = kr_state.rtableid;
+#endif
 	hdr.rtm_flags = RTF_PROTO1;
 	if (kroute->flags & F_BLACKHOLE)
 		hdr.rtm_flags |= RTF_BLACKHOLE;
@@ -1914,6 +1924,7 @@
 	iov[iovcnt++].iov_len = sizeof(mask);
 
 	if (kroute->labelid) {
+#if !defined(__FreeBSD__) /* FreeBSD has no route labeling. */
 		bzero(&label, sizeof(label));
 		label.sr_len = sizeof(label);
 		strlcpy(label.sr_label, rtlabel_id2name(kroute->labelid),
@@ -1924,6 +1935,7 @@
 		/* adjust iovec */
 		iov[iovcnt].iov_base = &label;
 		iov[iovcnt++].iov_len = sizeof(label);
+#endif /* !defined(__FreeBSD__) */
 	}
 
 retry:
@@ -1960,8 +1972,8 @@
 int
 fetchtable(u_int rtableid, int connected_only)
 {
-	size_t			 len;
-	int			 mib[7];
+	size_t		 	len;
+	int		 		mib[6];
 	char			*buf, *next, *lim;
 	struct rt_msghdr	*rtm;
 	struct sockaddr		*sa, *gw, *rti_info[RTAX_MAX];
@@ -1976,9 +1988,8 @@
 	mib[3] = 0;
 	mib[4] = NET_RT_DUMP;
 	mib[5] = 0;
-	mib[6] = rtableid;
 
-	if (sysctl(mib, 7, NULL, &len, NULL, 0) == -1) {
+	if (sysctl(mib, 6, NULL, &len, NULL, 0) == -1) {
 		if (rtableid != 0 && errno == EINVAL)	/* table nonexistant */
 			return (0);
 		log_warn("sysctl");
@@ -1988,7 +1999,7 @@
 		log_warn("fetchtable");
 		return (-1);
 	}
-	if (sysctl(mib, 7, buf, &len, NULL, 0) == -1) {
+	if (sysctl(mib, 6, buf, &len, NULL, 0) == -1) {
 		log_warn("sysctl");
 		free(buf);
 		return (-1);
@@ -2240,12 +2251,14 @@
 				continue;
 
 			connected_only = 0;
+#if !defined(__FreeBSD__) /* XXX: FreeBSD has no multiple routing tables */ 
 			if (rtm->rtm_tableid != kr_state.rtableid) {
 				if (rtm->rtm_tableid == 0)
 					connected_only = 1;
 				else
 					continue;
 			}
+#endif
 
 			if (dispatch_rtmsg_addr(rtm, rti_info,
 			    connected_only) == -1)
