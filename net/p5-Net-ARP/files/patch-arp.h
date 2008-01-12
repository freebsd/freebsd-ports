--- arp.h.orig	2008-01-06 21:14:49.000000000 +0800
+++ arp.h	2008-01-06 21:15:11.000000000 +0800
@@ -55,4 +55,6 @@
    u_char dest_ip[IP_ALEN];     // dest ip
 };
 
+#ifndef __i386__
 extern struct ether_addr *ether_aton (__const char *__asc) __THROW;
+#endif
