--- zebra/ioctl.c.orig	2018-03-12 00:53:37 UTC
+++ zebra/ioctl.c
@@ -395,10 +395,13 @@ void if_get_flags(struct interface *ifp)
 		strncpy(ifmr.ifm_name, ifp->name, IFNAMSIZ);
 
 		/* Seems not all interfaces implement this ioctl */
-		if (if_ioctl(SIOCGIFMEDIA, (caddr_t)&ifmr) < 0)
-			zlog_err("if_ioctl(SIOCGIFMEDIA) failed: %s",
-				 safe_strerror(errno));
-		else if (ifmr.ifm_status & IFM_AVALID) /* Link state is valid */
+		if (if_ioctl(SIOCGIFMEDIA, (caddr_t)&ifmr) < 0) {
+			/* Ignore EINVAL to avoid being too verbose */
+			if (errno != EINVAL)
+				zlog_err("if_ioctl(SIOCGIFMEDIA) failed: %s",
+					 safe_strerror(errno));
+		} else if (ifmr.ifm_status
+			   & IFM_AVALID) /* Link state is valid */
 		{
 			if (ifmr.ifm_status & IFM_ACTIVE)
 				SET_FLAG(ifreq.ifr_flags, IFF_RUNNING);
