diff -urN src/tun.c.orig src/tun.c
--- src/tun.c.orig	2008-06-28 17:38:35.000000000 +0100
+++ src/tun.c	2008-06-29 16:17:48.000000000 +0100
@@ -1,7 +1,7 @@
 /* 
  * Tunnel Interface Functions.
  * Copyright (C) 2002, 2003, 2004 Mondru AB.
- * Copyright (c) 2006-2007 David Bird <david@coova.com>
+ * Copyright (c) 2006-2008 David Bird <david@coova.com>
  * 
  * The contents of this file may be used under the terms of the GNU
  * General Public License Version 2, provided that the above copyright
@@ -226,7 +226,7 @@
   return 0;
 }
 
-int tun_gifindex(struct tun_t *this, int *index) {
+int tun_gifindex(struct tun_t *this, uint32_t *index) {
   struct ifreq ifr;
   int fd;
 
@@ -423,7 +423,7 @@
   return 0;
 }
 
-static int tuntap_interface(struct _net_interface *netif) {
+int tuntap_interface(struct _net_interface *netif) {
 #if defined(__linux__)
   struct ifreq ifr;
 
@@ -443,7 +443,6 @@
 #error  "Unknown platform!"
 #endif
 
-
 #if defined(__linux__)
   /* Open the actual tun device */
   if ((netif->fd  = open("/dev/net/tun", O_RDWR)) < 0) {
@@ -520,7 +519,6 @@
   /* Find suitable device */
   for (devnum = 0; devnum < 255; devnum++) { /* TODO 255 */ 
     snprintf(devname, sizeof(devname), "/dev/tun%d", devnum);
-    devname[sizeof(devname)] = 0;
     if ((netif->fd = open(devname, O_RDWR)) >= 0) break;
     if (errno != EBUSY) break;
   } 
@@ -530,7 +528,6 @@
   }
 
   snprintf(netif->devname, sizeof(netif->devname), "tun%d", devnum);
-  netif->devname[sizeof(netif->devname)-1] = 0;
 
   /* The tun device we found might have "old" IP addresses allocated */
   /* We need to delete those. This problem is not present on Linux */
@@ -538,13 +535,11 @@
   memset(&areq, 0, sizeof(areq));
 
   /* Set up interface name */
-  strncpy(areq.ifra_name, netif->devname, IFNAMSIZ);
-  areq.ifra_name[IFNAMSIZ-1] = 0; /* Make sure to terminate */
+  strncpy(areq.ifra_name, netif->devname, sizeof(areq.ifra_name));
 
   /* Create a channel to the NET kernel. */
   if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
-    log_err(errno,
-	    "socket() failed");
+    log_err(errno,"socket() failed");
     return -1;
   }
   
@@ -703,14 +698,15 @@
 
   if (this->cb_ind)
     return this->cb_ind(this, &packet, sbuf.len);
-
   return 0;
   
 #endif
 }
 
+/*
 static uint32_t dnatip[1024];
 static uint16_t dnatport[1024];
+*/
 
 int tun_encaps(struct tun_t *tun, void *pack, size_t len, int idx) {
 

