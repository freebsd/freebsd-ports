--- ospfd/ospf_packet.c.orig	2011-09-29 18:59:32.000000000 +0600
+++ ospfd/ospf_packet.c	2011-11-12 12:02:58.000000000 +0600
@@ -2116,7 +2116,7 @@
   
   ip_len = iph->ip_len;
   
-#if !defined(GNU_LINUX) && (OpenBSD < 200311)
+#if !defined(GNU_LINUX) && (OpenBSD < 200311) && (__FreeBSD_version < 1000000)
   /*
    * Kernel network code touches incoming IP header parameters,
    * before protocol specific processing.
