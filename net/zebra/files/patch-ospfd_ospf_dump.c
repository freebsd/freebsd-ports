--- ospfd/ospf_dump.c.orig	2003-11-04 20:10:17.000000000 +0100
+++ ospfd/ospf_dump.c	2014-03-18 14:22:06.123332679 +0100
@@ -607,7 +607,7 @@
 
   iph = (struct ip *) STREAM_PNT (s);
 
-#ifdef GNU_LINUX
+#if defined(GNU_LINUX) || defined(__FreeBSD__)
   length = ntohs (iph->ip_len);
 #else /* GNU_LINUX */
   length = iph->ip_len;
