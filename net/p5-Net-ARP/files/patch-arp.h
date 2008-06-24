--- arp.h.orig	2007-08-16 09:38:44.000000000 +0200
+++ arp.h	2008-06-24 14:47:24.000000000 +0200
@@ -54,5 +54,3 @@
    u_char dest_add[ETH_ALEN];   // dest mac
    u_char dest_ip[IP_ALEN];     // dest ip
 };
-
-extern struct ether_addr *ether_aton (__const char *__asc) __THROW;
