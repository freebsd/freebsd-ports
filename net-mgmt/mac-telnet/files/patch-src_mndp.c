--- src/mndp.c.orig	2024-06-19 14:43:14 UTC
+++ src/mndp.c
@@ -170,9 +170,12 @@ int mndp(int timeout, int batch_mode) {
 	return 0;
 }
 
+#define ether_addr_octet octet
+
 char *ether_ntoa_z(const struct ether_addr *addr) {
 	static char buf[18]; /* 12 digits + 5 colons + null terminator */
 	sprintf(buf, "%02x:%02x:%02x:%02x:%02x:%02x", addr->ether_addr_octet[0], addr->ether_addr_octet[1],
 			addr->ether_addr_octet[2], addr->ether_addr_octet[3], addr->ether_addr_octet[4], addr->ether_addr_octet[5]);
 	return buf;
 }
+#undef ether_addr_octet
