--- ospfd/kroute.c.orig	2009-04-29 15:07:32.000000000 -0400
+++ ospfd/kroute.c	2009-04-29 15:07:57.000000000 -0400
@@ -1024,9 +1024,11 @@
 	struct sockaddr_in	prefix;
 	struct sockaddr_in	nexthop;
 	struct sockaddr_in	mask;
+#if !defined(__FreeBSD__)
 	struct sockaddr_rtlabel	sa_rl;
-	int			iovcnt = 0;
 	const char		*label;
+#endif /* !defined(__FreeBSD__) */
+	int			iovcnt = 0;
 
 	if (kr_state.fib_sync == 0)
 		return (0);
@@ -1035,7 +1037,12 @@
 	bzero(&hdr, sizeof(hdr));
 	hdr.rtm_version = RTM_VERSION;
 	hdr.rtm_type = action;
+#if !defined(__FreeBSD__)
 	hdr.rtm_flags = RTF_PROTO2|RTF_MPATH;
+#else
+	/* No multipath routing in FreeBSD yet */
+	hdr.rtm_flags = RTF_PROTO2;
+#endif /* !defined(__FreeBSD__) */
 	if (action == RTM_CHANGE)	/* force PROTO2 reset the other flags */
 		hdr.rtm_fmask = RTF_PROTO2|RTF_PROTO1|RTF_REJECT|RTF_BLACKHOLE;
 	hdr.rtm_seq = kr_state.rtseq++;	/* overflow doesn't matter */
@@ -1080,6 +1087,7 @@
 	iov[iovcnt].iov_base = &mask;
 	iov[iovcnt++].iov_len = sizeof(mask);
 
+#if !defined(__FreeBSD__) /* FreeBSD has no route labeling. */
 	if (kroute->rtlabel != 0) {
 		sa_rl.sr_len = sizeof(sa_rl);
 		sa_rl.sr_family = AF_UNSPEC;
@@ -1096,6 +1104,7 @@
 		iov[iovcnt].iov_base = &sa_rl;
 		iov[iovcnt++].iov_len = sizeof(sa_rl);
 	}
+#endif /* !defined(__FreeBSD__) */
 
 
 retry:
@@ -1138,7 +1147,9 @@
 	struct rt_msghdr	*rtm;
 	struct sockaddr		*sa, *rti_info[RTAX_MAX];
 	struct sockaddr_in	*sa_in;
+#if !defined(__FreeBSD__)
 	struct sockaddr_rtlabel	*label;
+#endif
 	struct kroute_node	*kr;
 
 	mib[0] = CTL_NET;
@@ -1147,9 +1158,13 @@
 	mib[3] = AF_INET;
 	mib[4] = NET_RT_DUMP;
 	mib[5] = 0;
+#if !defined(__FreeBSD__) /* FreeBSD has no multiple routing tables */
 	mib[6] = 0;	/* rtableid */
 
 	if (sysctl(mib, 7, NULL, &len, NULL, 0) == -1) {
+#else
+	if (sysctl(mib, 6, NULL, &len, NULL, 0) == -1) {
+#endif /* !defined(__FreeBSD__) */
 		log_warn("sysctl");
 		return (-1);
 	}
@@ -1157,7 +1172,11 @@
 		log_warn("fetchtable");
 		return (-1);
 	}
+#if !defined(__FreeBSD__) /* FreeBSD has no multiple routing tables */
 	if (sysctl(mib, 7, buf, &len, NULL, 0) == -1) {
+#else
+	if (sysctl(mib, 6, buf, &len, NULL, 0) == -1) {
+#endif /* !defined(__FreeBSD__) */
 		log_warn("sysctl");
 		free(buf);
 		return (-1);
@@ -1230,6 +1249,7 @@
 			send_rtmsg(kr_state.fd, RTM_DELETE, &kr->r);
 			free(kr);
 		} else {
+#if !defined(__FreeBSD__) /* FreeBSD has no route labeling. */
 			if ((label = (struct sockaddr_rtlabel *)
 			    rti_info[RTAX_LABEL]) != NULL) {
 				kr->r.rtlabel =
@@ -1237,6 +1257,7 @@
 				kr->r.ext_tag =
 				    rtlabel_id2tag(kr->r.rtlabel);
 			}
+#endif /* !defined(__FreeBSD__) */
 			kroute_insert(kr);
 		}
 
@@ -1330,7 +1351,9 @@
 	struct ifa_msghdr	*ifam;
 	struct sockaddr		*sa, *rti_info[RTAX_MAX];
 	struct sockaddr_in	*sa_in;
+#if !defined(__FreeBSD__)
 	struct sockaddr_rtlabel	*label;
+#endif /* !defined(__FreeBSD__) */
 	struct kroute_node	*kr, *okr;
 	struct in_addr		 prefix, nexthop;
 	u_int8_t		 prefixlen;
@@ -1364,8 +1387,10 @@
 			sa = (struct sockaddr *)(rtm + 1);
 			get_rtaddrs(rtm->rtm_addrs, sa, rti_info);
 
+#if !defined(__FreeBSD__) /* XXX: FreeBSD has no multiple routing tables */
 			if (rtm->rtm_tableid != 0)
 				continue;
+#endif
 
 			if (rtm->rtm_pid == kr_state.pid) /* caused by us */
 				continue;
@@ -1462,6 +1487,7 @@
 				rtlabel_unref(kr->r.rtlabel);
 				kr->r.rtlabel = 0;
 				kr->r.ext_tag = 0;
+#if !defined(__FreeBSD__) /* FreeBSD has no route labeling. */
 				if ((label = (struct sockaddr_rtlabel *)
 				    rti_info[RTAX_LABEL]) != NULL) {
 					kr->r.rtlabel =
@@ -1469,6 +1495,7 @@
 					kr->r.ext_tag =
 					    rtlabel_id2tag(kr->r.rtlabel);
 				}
+#endif /* !defined(__FreeBSD__) */
 
 				if (kif_validate(kr->r.ifindex))
 					kr->r.flags &= ~F_DOWN;
@@ -1490,6 +1517,7 @@
 				kr->r.flags = flags;
 				kr->r.ifindex = ifindex;
 
+#if !defined(__FreeBSD__) /* FreeBSD has no route labeling */
 				if ((label = (struct sockaddr_rtlabel *)
 				    rti_info[RTAX_LABEL]) != NULL) {
 					kr->r.rtlabel =
@@ -1497,6 +1525,7 @@
 					kr->r.ext_tag =
 					    rtlabel_id2tag(kr->r.rtlabel);
 				}
+#endif /* !defined(__FreeBSD__) */
 
 				kroute_insert(kr);
 			}
