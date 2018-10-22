--- zebra/ioctl.c.orig	2018-10-22 05:34:13 UTC
+++ zebra/ioctl.c
@@ -415,7 +415,9 @@ void if_get_flags(struct interface *ifp)
 
 		/* Seems not all interfaces implement this ioctl */
 		if (if_ioctl(SIOCGIFMEDIA, (caddr_t)&ifmr) < 0)
-			flog_err_sys(LIB_ERR_SYSTEM_CALL,
+			/* Ignore EINVAL to avoid being too verbose */
+			if (errno != EINVAL)
+				flog_err_sys(LIB_ERR_SYSTEM_CALL,
 				     "if_ioctl(SIOCGIFMEDIA) failed: %s",
 				     safe_strerror(errno));
 		else if (ifmr.ifm_status & IFM_AVALID) /* Link state is valid */
