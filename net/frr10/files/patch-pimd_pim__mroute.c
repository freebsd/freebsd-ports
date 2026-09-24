Four fixes to the multicast routing plumbing on BSD.

1. The mroute socket asked for the ingress ifindex with IP_PKTINFO only, which
   is Linux and Solaris.  pim_mroute_msg() dispatches every IPPROTO_IGMP packet
   read from that socket to process_igmp_packet(buf, ifindex), so on BSD ifindex
   stayed -1, if_lookup_by_index(-1) returned NULL, and every membership report
   was dropped without a log line.  Use setsockopt_ifindex(), which picks the
   right option per platform.

2. pimreg is a pseudo interface with no address, which is fine on Linux where
   the vif is added by ifindex.  BSD adds a vif by local address and add_vif()
   rejects INADDR_ANY before it looks at VIFF_REGISTER, so the register vif was
   never created and no PIM Register was ever built.  Lend it the address of
   another PIM interface, as net/pimd's update_reg_vif() does.

3. SIOCGETSGCNT is gated on PRIV_NETINET_MROUTE in X_mrt_ioctl() and pimd has
   dropped to its unprivileged user, so the (S,G) counters stayed at zero -- the
   counters the keepalive timer and the SPT switchover decision read.

4. MRT_DEL_MFC was not wrapped in frr_with_privs while the MRT_ADD_MFC that
   installs the entry is, so every mroute removal failed with EPERM and left the
   entry in the kernel with nothing in the daemon referring to it.

Plus: a last hop router has to build (S,G) state itself here.  Linux resolves an
(S,G) miss against the (*,G) entry in ipmr_cache_find_any() and forwards the
packet; BSD's mfc_find() matches the source exactly and has no wildcard mfc, so
the kernel raises a NOCACHE upcall for every new source instead and
pim_mroute_nocache_forward_existing() returned early for want of an (S,G)
upstream -- leaving an mfc entry with an empty outgoing list that silenced
further upcalls and black-holed the traffic.

Submitted upstream: https://github.com/FRRouting/frr/pull/23455

--- pimd/pim_mroute.c.orig	2026-09-24 18:59:47 UTC
+++ pimd/pim_mroute.c	2026-09-24 18:59:47 UTC
@@ -113,33 +113,18 @@ int pim_mroute_set(struct pim_instance *pim, int enable)
 		}
 	}
 
-#if defined(HAVE_IP_PKTINFO)
-	if (enable) {
-		/* Linux and Solaris IP_PKTINFO */
-		data = 1;
-		if (setsockopt(pim->mroute_socket, PIM_IPPROTO, IP_PKTINFO,
-			       &data, data_len)) {
-			zlog_warn(
-				"Could not set IP_PKTINFO on socket fd=%d: errno=%d: %s",
-				pim->mroute_socket, errno,
-				safe_strerror(errno));
-		}
-	}
-#endif
-
-#if PIM_IPV == 6
-	if (enable) {
-		/* Linux and Solaris IPV6_PKTINFO */
-		data = 1;
-		if (setsockopt(pim->mroute_socket, PIM_IPPROTO,
-			       IPV6_RECVPKTINFO, &data, data_len)) {
-			zlog_warn(
-				"Could not set IPV6_RECVPKTINFO on socket fd=%d: errno=%d: %s",
-				pim->mroute_socket, errno,
-				safe_strerror(errno));
-		}
-	}
-#endif
+	/*
+	 * pim_mroute_msg() hands every IPPROTO_IGMP packet read from this
+	 * socket to process_igmp_packet(), which needs the ingress ifindex to
+	 * find the interface the report came in on; without it
+	 * if_lookup_by_index() fails and every IGMP report is dropped
+	 * silently.  setsockopt_ifindex() asks for it with whatever this
+	 * platform provides -- IP_PKTINFO on Linux and Solaris, IP_RECVIF on
+	 * BSD, IPV6_RECVPKTINFO for v6.
+	 */
+	if (enable && setsockopt_ifindex(PIM_AF, pim->mroute_socket, 1) < 0)
+		zlog_warn("Could not request the ingress ifindex on socket fd=%d",
+			  pim->mroute_socket);
 	setsockopt_so_recvbuf(pim->mroute_socket, 1024 * 1024 * 8);
 
 	if (set_nonblocking(pim->mroute_socket) < 0) {
@@ -194,10 +179,51 @@ static void pim_mroute_nocache_forward_existing(struct interface *ifp, pim_sgadd
 	struct pim_nexthop rpf_nh;
 	struct prefix grp;
 	struct pim_rpf old;
+	bool on_rpt = false;
 
 	up = pim_upstream_find(pim, sg);
-	if (!up)
-		return;
+	if (!up) {
+		/*
+		 * No (S,G) state yet.  On Linux this upcall would never have
+		 * been raised: ipmr_cache_find_any() resolves the lookup
+		 * against the (*,G) entry and the kernel forwards the packet
+		 * itself.  BSD's mfc_find() matches the source exactly and has
+		 * no wildcard mfc, so a last hop router whose receivers joined
+		 * (*,G) is asked about every new source and has to build the
+		 * (S,G) itself, or the traffic stops one hop short of the
+		 * receiver.
+		 *
+		 * Only do so when the (*,G) it would inherit from exists --
+		 * otherwise this is a source nobody here asked for.  The
+		 * creation is the same one the WHOLEPKT path uses for an LHR;
+		 * the rest of this function resolves the iif and inherits the
+		 * olist, and returns without installing anything if there turn
+		 * out to be no receivers.
+		 */
+		pim_sgaddr star_g = *sg;
+
+		star_g.src = PIMADDR_ANY;
+		if (!pim_upstream_find(pim, &star_g))
+			return;
+
+		up = pim_upstream_add(pim, sg, ifp, PIM_UPSTREAM_FLAG_MASK_SRC_LHR, __func__, NULL);
+		if (!up)
+			return;
+
+		/*
+		 * The keepalive is this entry's expiry: when the source stops,
+		 * it fires and pim_upstream_keep_alive_timer_proc() releases
+		 * the SRC_LHR reference, taking the mfc with it.  It no longer
+		 * drags the router onto the source tree either -- whether that
+		 * switch may happen is decided by spt-switchover, in
+		 * pim_upstream_evaluate_join_desired().
+		 */
+		pim_upstream_keep_alive_timer_start(up, pim->keep_alive_time);
+
+		if (PIM_DEBUG_MROUTE)
+			zlog_debug("%s: %pSG NOCACHE on %s, creating (S,G) from (*,G) on LHR",
+				   __func__, sg, ifp->name);
+	}
 
 	memset(&rpf_nh, 0, sizeof(rpf_nh));
 	pim_addr_to_prefix(&grp, sg->grp);
@@ -216,14 +242,31 @@ static void pim_mroute_nocache_forward_existing(struct interface *ifp, pim_sgadd
 	}
 
 	if (!rpf_nh.interface || rpf_nh.interface->ifindex != ifp->ifindex) {
-		if (PIM_DEBUG_MROUTE_DETAIL)
-			zlog_debug("%s: %pSG NOCACHE on %s, RPF interface is %s", __func__, sg,
-				   ifp->name, rpf_nh.interface ? rpf_nh.interface->name : "(none)");
-		return;
+		/*
+		 * Not the RPF interface towards the source -- which on a
+		 * shared tree is the ordinary case, not an error: the packet
+		 * comes from the RP, and it is the (*,G) this (S,G) inherits
+		 * from that knows the interface it arrives on.  Forward it
+		 * along the RPT instead of dropping it; Linux's wildcard mfc
+		 * does exactly that without involving the daemon at all.
+		 *
+		 * A packet on neither interface is genuinely unexpected, and
+		 * still returns.
+		 */
+		if (!up->parent || !up->parent->rpf.source_nexthop.interface ||
+		    up->parent->rpf.source_nexthop.interface->ifindex != ifp->ifindex) {
+			if (PIM_DEBUG_MROUTE_DETAIL)
+				zlog_debug("%s: %pSG NOCACHE on %s, RPF interface is %s", __func__,
+					   sg, ifp->name,
+					   rpf_nh.interface ? rpf_nh.interface->name : "(none)");
+			return;
+		}
+		on_rpt = true;
 	}
 
-	if (up->rpf.source_nexthop.interface != rpf_nh.interface ||
-	    pim_addr_cmp(up->rpf.source_nexthop.mrib_nexthop_addr, rpf_nh.mrib_nexthop_addr)) {
+	if (!on_rpt &&
+	    (up->rpf.source_nexthop.interface != rpf_nh.interface ||
+	     pim_addr_cmp(up->rpf.source_nexthop.mrib_nexthop_addr, rpf_nh.mrib_nexthop_addr))) {
 		enum pim_rpf_result rpf_result;
 
 		memset(&old, 0, sizeof(old));
@@ -233,6 +276,16 @@ static void pim_mroute_nocache_forward_existing(struct interface *ifp, pim_sgadd
 			pim_zebra_upstream_rpf_changed(pim, up, &old);
 	}
 
+	/*
+	 * An (S,G) forwarding off the shared tree takes its iif from the
+	 * parent rather than from the route to the source, and USE_RPT is
+	 * what pim_upstream_get_mroute_iif() reads to pick it.  Without this
+	 * the entry would be installed pointing at the interface the traffic
+	 * is not arriving on.
+	 */
+	if (on_rpt)
+		pim_upstream_update_use_rpt(up, false /*update_mroute*/);
+
 	pim_upstream_inherited_olist_decide(pim, up);
 	if (pim_upstream_empty_inherited_olist(up)) {
 		if (PIM_DEBUG_MROUTE_DETAIL)
@@ -241,10 +294,21 @@ static void pim_mroute_nocache_forward_existing(struct interface *ifp, pim_sgadd
 		return;
 	}
 
-	if (up->sptbit != PIM_UPSTREAM_SPTBIT_TRUE)
+	/* Only the source tree sets the SPT bit; on the RPT we have not
+	 * switched trees and must not claim to have.
+	 */
+	if (!on_rpt && up->sptbit != PIM_UPSTREAM_SPTBIT_TRUE)
 		pim_upstream_set_sptbit(up, ifp);
 
-	PIM_UPSTREAM_FLAG_SET_SRC_STREAM(up->flags);
+	/*
+	 * SRC_STREAM says this entry exists because traffic is flowing on the
+	 * source tree, and the keepalive expiry releases the stream reference
+	 * that goes with it.  An (S,G) forwarding off the shared tree is not
+	 * that: its reference is SRC_LHR, and it has to expire through that
+	 * branch instead.
+	 */
+	if (!on_rpt)
+		PIM_UPSTREAM_FLAG_SET_SRC_STREAM(up->flags);
 	up->channel_oil->cc.pktcnt++;
 
 	pim_upstream_update_join_desired(pim, up);
@@ -1618,6 +1682,38 @@ int pim_mroute_add_vif(struct interface *ifp, pim_addr ifaddr,
 #ifdef VIFF_USE_IFINDEX
 	vc.vc_lcl_ifindex = ifp->ifindex;
 #else
+	if (ifaddr.s_addr == INADDR_ANY && (flags & VIFF_REGISTER)) {
+		/*
+		 * pimreg is a pseudo interface with no address of its own
+		 * (pim_if_create_pimreg()), which on Linux is fine: the vif is
+		 * added by ifindex.  BSD adds a vif by local address, and its
+		 * add_vif() rejects INADDR_ANY before it ever looks at
+		 * VIFF_REGISTER -- even though the same function documents
+		 * that a register vif "does not really need a valid local
+		 * interface".  Without an address here the register vif is
+		 * never created, so the first hop router's mfc entry points at
+		 * a vif that does not exist, no PIM Register is ever built,
+		 * and the RP never learns of a source behind it.
+		 *
+		 * Lend it the address of another PIM interface, and fall back
+		 * to a loopback address when none has one yet, since only
+		 * non-nullness is actually required.
+		 */
+		struct interface *tmp_ifp;
+
+		FOR_ALL_INTERFACES (pim_ifp->pim->vrf, tmp_ifp) {
+			struct pim_interface *tmp_pim_ifp = tmp_ifp->info;
+
+			if (!tmp_pim_ifp || tmp_ifp == ifp)
+				continue;
+			if (pim_addr_is_any(tmp_pim_ifp->primary_address))
+				continue;
+			ifaddr = tmp_pim_ifp->primary_address;
+			break;
+		}
+		if (ifaddr.s_addr == INADDR_ANY)
+			ifaddr.s_addr = htonl(INADDR_LOOPBACK + 1);
+	}
 	if (ifaddr.s_addr == INADDR_ANY) {
 		zlog_warn(
 			"%s: unnumbered interfaces are not supported on this platform",
@@ -1973,8 +2069,18 @@ int pim_mroute_del(struct channel_oil *c_oil, const char *name)
 		return -2;
 	}
 
-	err = setsockopt(pim->mroute_socket, PIM_IPPROTO, MRT_DEL_MFC,
-			 &c_oil->oil, sizeof(c_oil->oil));
+	/*
+	 * Privileged, exactly as the MRT_ADD_MFC that put the entry there is:
+	 * a kernel that checks (FreeBSD gates the mroute setsockopts on
+	 * PRIV_NETINET_MROUTE) otherwise answers EPERM, and pimd goes on to
+	 * free its own state, leaving the mfc installed with nothing left to
+	 * remove it.
+	 */
+	frr_with_privs (&pimd_privs) {
+		err = setsockopt(pim->mroute_socket, PIM_IPPROTO, MRT_DEL_MFC, &c_oil->oil,
+				 sizeof(c_oil->oil));
+	}
+
 	if (err) {
 		if (PIM_DEBUG_MROUTE)
 			zlog_warn(
@@ -2001,6 +2107,7 @@ void pim_mroute_update_counters(struct channel_oil *c_oil)
 {
 	struct pim_instance *pim = c_oil->pim;
 	pim_sioc_sg_req sgreq;
+	int err;
 
 	c_oil->cc.oldpktcnt = c_oil->cc.pktcnt;
 	c_oil->cc.oldbytecnt = c_oil->cc.bytecnt;
@@ -2031,7 +2138,22 @@ void pim_mroute_update_counters(struct channel_oil *c_oil)
 	sgreq.src = c_oil->oil.mf6cc_origin;
 	sgreq.grp = c_oil->oil.mf6cc_mcastgrp;
 #endif
-	if (ioctl(pim->mroute_socket, PIM_SIOCGETSGCNT, &sgreq)) {
+#ifdef GNU_LINUX
+	err = ioctl(pim->mroute_socket, PIM_SIOCGETSGCNT, &sgreq);
+#else
+	/*
+	 * BSD gates this ioctl on PRIV_NETINET_MROUTE (X_mrt_ioctl()) and pimd
+	 * has long since dropped to its unprivileged user, so every call
+	 * returned EPERM and the (S,G) counters stayed at zero -- which is
+	 * what the keepalive timer and the SPT switchover decision are read
+	 * from.
+	 */
+	frr_with_privs (&pimd_privs) {
+		err = ioctl(pim->mroute_socket, PIM_SIOCGETSGCNT, &sgreq);
+	}
+#endif
+
+	if (err) {
 		pim_sgaddr sg;
 
 		sg.src = *oil_origin(c_oil);
