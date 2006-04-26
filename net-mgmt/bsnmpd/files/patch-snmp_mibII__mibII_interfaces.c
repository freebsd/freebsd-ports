--- snmp_mibII/mibII_interfaces.c.orig	Fri Apr 21 22:31:19 2006
+++ snmp_mibII/mibII_interfaces.c	Fri Apr 21 22:37:11 2006
@@ -289,8 +289,20 @@
 		 * cable) and hence return 'dormant'.
 		 */
 		if (ifp->mib.ifmd_flags & IFF_RUNNING) {
-			if (ifp->mib.ifmd_data.ifi_link_state ==
-			    LINK_STATE_DOWN)
+#ifndef HAVE_MIB_LINKSTATE
+#define MIB_LINKSTATE	MIBIF_PRIV(ifp)->pr_link_state
+			struct ifmediareq ifmr;
+			memset(&ifmr, 0, sizeof(ifmr));
+			strncpy(ifmr.ifm_name, ifp->name, sizeof(ifmr.ifm_name));
+			if (ioctl(mib_netsock, SIOCGIFMEDIA, (caddr_t)&ifmr) < 0)
+			       MIB_LINKSTATE = LINK_STATE_UNKNOWN;
+			else 
+				MIB_LINKSTATE = (ifmr.ifm_status & IFM_ACTIVE) ? 
+					LINK_STATE_UP: LINK_STATE_DOWN;
+#else
+#define MIB_LINKSTATE	ifp->mib.ifmd_data.ifi_link_state
+#endif
+			if (MIB_LINKSTATE == LINK_STATE_DOWN)
 				value->v.integer = 5;   /* state dormant */
 			else
 				value->v.integer = 1;   /* state up */
