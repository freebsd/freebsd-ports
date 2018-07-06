--- zebra/ioctl.c.orig	2018-06-08 01:39:07 UTC
+++ zebra/ioctl.c
@@ -430,10 +430,13 @@ void if_get_flags(struct interface *ifp)
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
