--- mod_evasive24.c.orig	2025-10-29 18:29:03 UTC
+++ mod_evasive24.c
@@ -250,26 +250,24 @@ static void ipv6_cidr_bits_to_mask(unsigned long cidr_
 
 static void ipv6_cidr_bits_to_mask(unsigned long cidr_bits, struct in6_addr *mask)
 {
-    for (unsigned i = 0; i < 4; i++) {
-        if (cidr_bits == 0) {
-            mask->s6_addr32[i] = 0;
-        } else if (cidr_bits >= 32) {
-            mask->s6_addr32[i] = ~UINT32_C(0);
-        } else {
-            mask->s6_addr32[i] = htobe32(~((UINT32_C(1) << (32 - cidr_bits)) - 1));
-        }
+    if (cidr_bits > 128) cidr_bits = 128;
+    memset(mask, 0, sizeof(*mask));
 
-        if (cidr_bits >= 32)
-            cidr_bits -= 32;
-        else
-            cidr_bits = 0;
-    }
+    unsigned full = (unsigned)(cidr_bits / 8);
+    unsigned rem  = (unsigned)(cidr_bits % 8);
+
+    for (unsigned i = 0; i < full && i < 16; i++)
+        mask->s6_addr[i] = 0xFF; //filling
+
+    // Set remaining partial bits in the next byte
+    if (rem && full < 16) //partial bits
+        mask->s6_addr[full] = (uint8_t)(0xFFu << (8 - rem));
 }
 
 static void ipv6_apply_mask(struct in6_addr *restrict addr, const struct in6_addr *restrict mask)
 {
-    for (unsigned i = 0; i < 4; i++)
-        addr->s6_addr32[i] &= mask->s6_addr32[i];
+    for (unsigned i = 0; i < 16; i++)
+        addr->s6_addr[i] &= mask->s6_addr[i];
 }
 
 static const char *whitelist_ip(__attribute__((unused)) cmd_parms *cmd, void *dconfig, const char *ip)
