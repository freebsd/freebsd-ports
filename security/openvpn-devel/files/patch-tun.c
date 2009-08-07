# This patch by Stefan Bethke fixes FreeBSD 8 compatibility
# in topology subnet mode, # and makes sure that the tun interface is
# correctly configured. Contact: stb at lassitu dot de

--- /home/stb/tun.c.orig	2009-08-05 14:25:55.204943408 +0200
+++ tun.c	2009-08-05 17:57:51.886753309 +0200
@@ -863,11 +863,10 @@
       else {
 	if (tt->topology == TOP_SUBNET)
             argv_printf (&argv,
-                              "%s %s %s %s netmask %s mtu %d up",
+                              "%s %s %s netmask %s mtu %d up",
                               IFCONFIG_PATH,
                               actual,
                               ifconfig_local,
-                              ifconfig_local,
                               ifconfig_remote_netmask,
                               tun_mtu
                               );
@@ -1745,14 +1744,19 @@
 {
   open_tun_generic (dev, dev_type, dev_node, ipv6, true, true, tt);
 
-  if (tt->fd >= 0)
+  if (tt->fd >= 0 && tt->type == DEV_TYPE_TUN)
     {
       int i = 0;
 
-      /* Disable extended modes */
-      ioctl (tt->fd, TUNSLMODE, &i);
+      i = tt->topology == TOP_SUBNET ? IFF_BROADCAST : IFF_POINTOPOINT;
+      i |= IFF_MULTICAST;
+      if (ioctl (tt->fd, TUNSIFMODE, &i) < 0) {
+	msg (M_WARN | M_ERRNO, "ioctl(TUNSIFMODE): %s", strerror(errno));
+      }
       i = 1;
-      ioctl (tt->fd, TUNSIFHEAD, &i);
+      if (ioctl (tt->fd, TUNSIFHEAD, &i) < 0) {
+	msg (M_WARN | M_ERRNO, "ioctl(TUNSIFHEAD): %s", strerror(errno));
+      }
     }
 }
 
