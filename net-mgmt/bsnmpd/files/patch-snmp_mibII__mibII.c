--- snmp_mibII/mibII.c	Mon Feb 27 13:03:15 2006
+++ snmp_mibII/mibII.c	Fri Apr 21 20:44:26 2006
@@ -420,6 +420,15 @@
 	size_t len;
 	void *newmib;
 	struct ifmibdata oldmib = ifp->mib;
+#ifdef HAVE_MIB_LINKSTATE
+#define MIB_LINKSTATE	ifp->mib.ifmd_data.ifi_link_state
+#define OLD_LINKSTATE	oldmib.ifmd_data.ifi_link_state
+#else
+#define MIB_LINKSTATE	MIBIF_PRIV(ifp)->pr_link_state
+#define OLD_LINKSTATE	old_link_state
+	struct ifmediareq ifmr;
+	uint8_t old_link_state = MIB_LINKSTATE;
+#endif
 
 	if (fetch_generic_mib(ifp, &oldmib) == -1)
 		return (-1);
@@ -429,12 +438,18 @@
 	 * generated just after ifOperStatus leaves, or just before it
 	 * enters, the down state, respectively;"
 	 */
-	if (ifp->trap_enable && ifp->mib.ifmd_data.ifi_link_state !=
-	    oldmib.ifmd_data.ifi_link_state &&
-	    (ifp->mib.ifmd_data.ifi_link_state == LINK_STATE_DOWN ||
-	    oldmib.ifmd_data.ifi_link_state == LINK_STATE_DOWN))
-		link_trap(ifp, ifp->mib.ifmd_data.ifi_link_state ==
-		    LINK_STATE_UP ? 1 : 0);
+#ifndef HAVE_MIB_LINKSTATE
+	memset(&ifmr, 0, sizeof(ifmr));
+	strncpy(ifmr.ifm_name, ifp->name, sizeof(ifmr.ifm_name));
+	if (ioctl(mib_netsock, SIOCGIFMEDIA, (caddr_t)&ifmr) < 0)
+		MIB_LINKSTATE = LINK_STATE_UNKNOWN;
+	else MIB_LINKSTATE = (ifmr.ifm_status & IFM_ACTIVE) ? LINK_STATE_UP:
+		LINK_STATE_DOWN;
+#endif
+	if (ifp->trap_enable && MIB_LINKSTATE != OLD_LINKSTATE &&
+	   (MIB_LINKSTATE == LINK_STATE_DOWN ||
+	    OLD_LINKSTATE == LINK_STATE_DOWN))
+		link_trap(ifp, MIB_LINKSTATE == LINK_STATE_UP ? 1 : 0);
 
 	ifp->flags &= ~(MIBIF_HIGHSPEED | MIBIF_VERYHIGHSPEED);
 	if (ifp->mib.ifmd_data.ifi_baudrate > 20000000) {
@@ -774,7 +789,11 @@
 		ifp->counter_disc = get_ticks();
 	}
 	ifp->index = map->ifindex;
+#ifdef HAVE_MIB_LINKSTATE
 	ifp->mib.ifmd_data.ifi_link_state = LINK_STATE_UNKNOWN;
+#else
+	MIBIF_PRIV(ifp)->pr_link_state = LINK_STATE_UNKNOWN;
+#endif
 
 	INSERT_OBJECT_INT(ifp, &mibif_list);
 	mib_if_number++;
