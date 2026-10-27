--- mod_evasive24.c	2025-02-16 16:36:05 UTC
+++ mod_evasive24.c
@@ -248,35 +248,37 @@ err:
     return -1;
 }
 
+#if APR_HAVE_IPV6
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
+#endif
 
 static const char *whitelist_ip(__attribute__((unused)) cmd_parms *cmd, void *dconfig, const char *ip)
 {
     evasive_config *cfg = (evasive_config *) dconfig;
     struct in_addr ipv4;
+#if APR_HAVE_IPV6
     struct in6_addr ipv6, maskv6;
+#endif
     struct ip_node *newdata;
     const char *ip_parse = ip;
     char *ip_copy = NULL;
@@ -303,9 +305,11 @@ static const char *whitelist_ip(__attribute__((unused)
         family = AF_INET;
         wildcard = 1;
         rc = parse_wildcard(ip_parse, &ipv4, &maskv4);
+#if APR_HAVE_IPV6
     } else if (strchr(ip_parse, ':') != NULL) {
         family = AF_INET6;
         rc = inet_pton(AF_INET6, ip_parse, &ipv6);
+#endif
     } else {
         family = AF_INET;
         rc = inet_pton(AF_INET, ip_parse, &ipv4);
@@ -335,9 +339,11 @@ static const char *whitelist_ip(__attribute__((unused)
             maskv4 = ~((UINT32_C(1) << (32 - mask_bits)) - 1);
             maskv4 = htobe32(maskv4);
             ipv4.s_addr &= maskv4;
+#if APR_HAVE_IPV6
         } else {
             ipv6_cidr_bits_to_mask(mask_bits, &maskv6);
             ipv6_apply_mask(&ipv6, &maskv6);
+#endif
         }
     }
 
@@ -354,12 +360,14 @@ static const char *whitelist_ip(__attribute__((unused)
             .ip.v4 = ipv4,
             .mask.v4 = maskv4,
         };
+#if APR_HAVE_IPV6
     } else {
         cfg->ip_whitelist.data[cfg->ip_whitelist.size++] = (struct ip_node) {
             .family = AF_INET6,
             .ip.v6 = ipv6,
             .mask.v6 = maskv6,
         };
+#endif
     }
 
     return NULL;
@@ -544,7 +552,7 @@ static int access_checker(request_rec *r)
             if (stat(filename, &s)) {
                 file = fopen(filename, "w");
                 if (file != NULL) {
-                    fprintf(file, "%ld\n", getpid());
+                    fprintf(file, "%lu\n", (unsigned long)getpid());
                     fclose(file);
 
                     ap_log_rerror(APLOG_MARK, APLOG_WARNING, 0, r, "Blacklisting address %s: possible DoS attack.", r->useragent_ip);
@@ -608,9 +616,13 @@ static int is_whitelisted(const apr_sockaddr_t *client
             addrv4.s_addr &= node->mask.v4;
             rc = memcmp(&node->ip.v4, &addrv4, sizeof(node->ip.v4));
         } else {
+#if APR_HAVE_IPV6
             struct in6_addr addrv6 = client->sa.sin6.sin6_addr;
             ipv6_apply_mask(&addrv6, &node->mask.v6);
             rc = memcmp(&node->ip.v6, &addrv6, sizeof(node->ip.v6));
+#else
+            continue;
+#endif
         }
 
         if (rc == 0)
