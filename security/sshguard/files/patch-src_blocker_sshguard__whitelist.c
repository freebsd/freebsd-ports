--- src/blocker/sshguard_whitelist.c.orig	2020-12-31 17:06:03 UTC
+++ src/blocker/sshguard_whitelist.c
@@ -275,7 +275,7 @@ int whitelist_add_block6(const char *restrict address,
     bitlen = masklen % 8;
     bitmask = 0xFF << (8 - bitlen);
     ab.address.ip6.mask.s6_addr[bytelen] = bitmask;
-    memset(& ab.address.ip6.mask.s6_addr[bytelen+1], 0x00, sizeof(ab.address.ip6.mask.s6_addr) - bytelen);
+    memset(& ab.address.ip6.mask.s6_addr[bytelen+1], 0x00, sizeof(ab.address.ip6.mask.s6_addr) - bytelen - 1);
 
     if (! list_contains(& whitelist, &ab)) {
         list_append(& whitelist, &ab);
