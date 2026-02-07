--- gen/util.c.orig	2025-05-05 17:12:32 UTC
+++ gen/util.c
@@ -351,7 +351,11 @@ getiflinkaddr(const char *ifname, struct ether_addr *a
 			if ((sdl->sdl_type == IFT_ETHER) &&
 			    (sdl->sdl_alen == ETHER_ADDR_LEN)) {
 
+#ifdef CLLADDR
 				memcpy(addr, (const struct ether_addr *)CLLADDR(sdl), ETHER_ADDR_LEN);
+#else
+				memcpy(addr, (const struct ether_addr *)LLADDR(sdl), ETHER_ADDR_LEN);
+#endif
 				found = 1;
 				break;
 			}
