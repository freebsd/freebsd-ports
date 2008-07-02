--- zebra/ioctl.c	26 Feb 2008 14:02:24 -0000	1.15
+++ zebra/ioctl.c	1 Jul 2008 15:43:04 -0000
@@ -362,22 +362,29 @@ if_get_flags (struct interface *ifp)
       return;
     }
 #ifdef HAVE_BSD_LINK_DETECT /* Detect BSD link-state at start-up */
-  (void) memset(&ifmr, 0, sizeof(ifmr));
-  strncpy (&ifmr.ifm_name, ifp->name, IFNAMSIZ);
-  if (if_ioctl(SIOCGIFMEDIA, (caddr_t) &ifmr) < 0)
-    {
-      zlog_err("if_ioctl(SIOCGIFMEDIA) failed: %s", safe_strerror(errno));
-      return;
-    }
-  if (ifmr.ifm_status & IFM_AVALID) /* Link state is valid */
+
+  /* Per-default, IFF_RUNNING is held high, unless link-detect says
+   * otherwise - we abuse IFF_RUNNING inside zebra as a link-state flag,
+   * following practice on Linux and Solaris kernels
+   */
+  SET_FLAG(ifreq.ifr_flags, IFF_RUNNING);
+  
+  if (CHECK_FLAG (ifp->status, ZEBRA_INTERFACE_LINKDETECTION))
     {
-      if (ifmr.ifm_status & IFM_ACTIVE)
-	SET_FLAG(ifreq.ifr_flags, IFF_RUNNING);
-      else
-	UNSET_FLAG(ifreq.ifr_flags, IFF_RUNNING);
-    }
-  else /* Force always up */
-    SET_FLAG(ifreq.ifr_flags, IFF_RUNNING);
+      (void) memset(&ifmr, 0, sizeof(ifmr));
+      strncpy (&ifmr.ifm_name, ifp->name, IFNAMSIZ);
+      
+      /* Seems not all interfaces implement this ioctl */
+      if (if_ioctl(SIOCGIFMEDIA, (caddr_t) &ifmr) < 0)
+        zlog_err("if_ioctl(SIOCGIFMEDIA) failed: %s", safe_strerror(errno));
+      else if (ifmr.ifm_status & IFM_AVALID) /* Link state is valid */
+        {
+          if (ifmr.ifm_status & IFM_ACTIVE)
+            SET_FLAG(ifreq.ifr_flags, IFF_RUNNING);
+          else
+            UNSET_FLAG(ifreq.ifr_flags, IFF_RUNNING);
+        }
+  }
 #endif /* HAVE_BSD_LINK_DETECT */
 
   if_flags_update (ifp, (ifreq.ifr_flags & 0x0000ffff));
