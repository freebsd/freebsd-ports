--- arp.h.orig	2013-06-24 05:14:10 UTC
+++ arp.h
@@ -58,8 +58,6 @@ struct my_arphdr {
    u_char dest_add[ETH_ALEN];   // dest mac
    u_char dest_ip[IP_ALEN];     // dest ip
 };
-
-extern struct ether_addr *ether_aton (__const char *__asc) __THROW;
 extern int get_mac_linux(const char *dev, char *mac);
 extern int get_mac_bsd(const char *dev, char *mac);
 extern int arp_lookup_linux(const char *dev, const char *ip, char *mac);
