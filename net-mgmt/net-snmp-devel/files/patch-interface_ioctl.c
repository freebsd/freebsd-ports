--- ./agent/mibgroup/if-mib/data_access/interface_ioctl.c.orig	Mon Oct 25 12:57:23 2004
+++ ./agent/mibgroup/if-mib/data_access/interface_ioctl.c	Mon Oct 25 12:56:33 2004
@@ -385,6 +385,10 @@
     if (rc < 0)
         return 0;
 
+#if defined(__FreeBSD__)
+    return ifrq.ifr_index;
+#else
     return ifrq.ifr_ifindex;
+#endif
 #endif /* SIOCGIFINDEX */
 }
