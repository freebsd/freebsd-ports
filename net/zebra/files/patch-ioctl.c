--- zebra/ioctl.c.orig	Wed Dec 12 18:02:16 2001
+++ zebra/ioctl.c	Wed Dec 12 18:02:30 2001
@@ -478,6 +478,9 @@
   mask.sin6_len = sizeof (struct sockaddr_in6);
 #endif
   memcpy (&addreq.ifra_prefixmask, &mask, sizeof (struct sockaddr_in6));
+
+  addreq.ifra_lifetime.ia6t_vltime = 0xffffffff;
+  addreq.ifra_lifetime.ia6t_pltime = 0xffffffff;
   
   ret = if_ioctl_ipv6 (SIOCAIFADDR_IN6, (caddr_t) &addreq);
   if (ret < 0)
