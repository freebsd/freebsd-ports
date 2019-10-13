--- ospfd/ospf_packet.c.orig	2005-06-21 02:58:24.000000000 +0200
+++ ospfd/ospf_packet.c	2014-03-18 14:22:06.129332906 +0100
@@ -528,7 +528,7 @@
   iph.ip_hl = sizeof (struct ip) >> 2;
   iph.ip_v = IPVERSION;
   iph.ip_tos = IPTOS_PREC_INTERNETCONTROL;
-#if defined(__NetBSD__) || defined(__FreeBSD__)
+#if defined(__NetBSD__)
   iph.ip_len = iph.ip_hl*4 + op->length;
 #else
   iph.ip_len = htons (iph.ip_hl*4 + op->length);
@@ -1893,13 +1894,13 @@
       return NULL;
     }
 
-#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(OpenBSD_IP_LEN)
+#if defined(__NetBSD__) || defined(OpenBSD_IP_LEN)
   ip_len = iph.ip_len;
 #else
   ip_len = ntohs (iph.ip_len);
 #endif
 
-#if !defined(GNU_LINUX) && !defined(OpenBSD_IP_LEN)
+#if !defined(GNU_LINUX) && !defined(OpenBSD_IP_LEN) && !defined(__FreeBSD__)
   /*
    * Kernel network code touches incoming IP header parameters,
    * before protocol specific processing.
