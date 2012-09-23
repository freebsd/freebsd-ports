--- ./if.c.orig	2012-08-17 20:31:25.000000000 +0200
+++ ./if.c	2012-09-23 17:27:26.000000000 +0200
@@ -274,7 +274,7 @@
 * traffic on this network.
 ***********************************************************************/
 int
-openInterface(char const *ifname, UINT16_t type, unsigned char *hwaddr)
+openInterface(char const *ifname, UINT16_t type, unsigned char *hwaddr, UINT16_t *mtu)
 {
     static int fd = -1;
     char bpfName[32];
@@ -285,7 +285,12 @@
     int i;
 
     /* BSD only opens one socket for both Discovery and Session packets */
+#if defined(__FreeBSD__)
+    /* Confirmed for FreeBSD 4.8-R [SeaD] */
+    if (!hwaddr) {
+#else
     if (fd >= 0) {
+#endif
 	return fd;
     }
 
@@ -395,6 +400,8 @@
 	rp_fatal(buffer);
     }
 
+    if (mtu) *mtu = ifr.ifr_mtu;
+
     syslog(LOG_INFO, "Interface=%.16s HWaddr=%02X:%02X:%02X:%02X:%02X:%02X Device=%.32s Buffer size=%d",
 	   ifname,
 	   hwaddr[0], hwaddr[1], hwaddr[2],
