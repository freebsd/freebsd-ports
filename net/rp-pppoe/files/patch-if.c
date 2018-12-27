--- if.c.orig	2018-11-25 22:25:28 UTC
+++ if.c
@@ -276,7 +276,7 @@ initFilter(int fd, UINT16_t type, unsigned char *hwadd
 * traffic on this network.
 ***********************************************************************/
 int
-openInterface(char const *ifname, UINT16_t type, unsigned char *hwaddr)
+openInterface(char const *ifname, UINT16_t type, unsigned char *hwaddr, UINT16_t *mtu)
 {
     static int fd = -1;
     char bpfName[32];
@@ -287,7 +287,12 @@ openInterface(char const *ifname, UINT16_t type, unsig
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
 
@@ -396,6 +401,8 @@ openInterface(char const *ifname, UINT16_t type, unsig
 		ifname);
 	rp_fatal(buffer);
     }
+
+    if (mtu) *mtu = ifr.ifr_mtu;
 
     syslog(LOG_INFO, "Interface=%.16s HWaddr=%02X:%02X:%02X:%02X:%02X:%02X Device=%.32s Buffer size=%d",
 	   ifname,
