--- src/names/eth_resolv.c.orig	2017-03-18 16:11:42 UTC
+++ src/names/eth_resolv.c
@@ -26,8 +26,9 @@
 #include <stdlib.h>
 #include <string.h>
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <net/ethernet.h>
-#include <netinet/ether.h>
 
 #include <glib.h>
 
@@ -48,8 +49,8 @@ static int ether_tree_cmp(gconstpointer ga, gconstpoin
   const struct ether_addr *a = ga;
   const struct ether_addr *b = gb;
 
-  return memcmp(&a->ether_addr_octet, &b->ether_addr_octet,
-                sizeof(a->ether_addr_octet));
+  return memcmp(&a->octet, &b->octet,
+                sizeof(a->octet));
 }
 
 static void add_ether_ent(const struct ether_addr *addr, const char *hostname)
@@ -118,7 +119,7 @@ const char *get_ether_name(const unsigned char *addr_b
   struct ether_ent *ent;
   size_t addrstr_size;
 
-  memcpy(&addr.ether_addr_octet, addr_bytes, sizeof(addr.ether_addr_octet));
+  memcpy(&addr.octet, addr_bytes, sizeof(addr.octet));
 
   ent = g_tree_lookup(ethers, &addr);
   if (ent)
@@ -129,9 +130,9 @@ const char *get_ether_name(const unsigned char *addr_b
   ent = g_malloc(sizeof(*ent) + addrstr_size);
   ent->addr = addr;
   snprintf(ent->hostname, addrstr_size, "%02x:%02x:%02x:%02x:%02x:%02x",
-           addr.ether_addr_octet[0], addr.ether_addr_octet[1],
-           addr.ether_addr_octet[2], addr.ether_addr_octet[3],
-           addr.ether_addr_octet[4], addr.ether_addr_octet[5]);
+           addr.octet[0], addr.octet[1],
+           addr.octet[2], addr.octet[3],
+           addr.octet[4], addr.octet[5]);
   g_tree_insert(ethers, &ent->addr, ent);
   return ent->hostname;
 }
