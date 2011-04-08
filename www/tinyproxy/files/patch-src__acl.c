--- src/acl.c.orig
+++ src/acl.c
@@ -66,8 +66,8 @@ struct acl_s {
  *
  */
 static int
-fill_netmask_array (char *bitmask_string, unsigned char array[],
-                    size_t len)
+fill_netmask_array (char *bitmask_string, int v6,
+                    unsigned char array[], size_t len)
 {
         unsigned int i;
         unsigned long int mask;
@@ -81,7 +81,14 @@ fill_netmask_array (char *bitmask_string, unsigned char array[],
             || (errno != 0 && mask == 0) || (endptr == bitmask_string))
                 return -1;
 
-        /* valid range for a bit mask */
+        if (v6 == 0) {
+                /* The mask comparison is done as an IPv6 address, so
+                 * convert to a longer mask in the case of IPv4
+                 * addresses. */
+                mask += 12 * 8;
+        }
+
+        /* check valid range for a bit mask */
         if (mask > (8 * len))
                 return -1;
 
@@ -163,6 +170,9 @@ insert_acl (char *location, acl_access_t access_type, vector_t *access_list)
                  */
                 p = strchr (location, '/');
                 if (p != NULL) {
+                        char dst[sizeof(struct in6_addr)];
+                        int v6;
+
                         /*
                          * We have a slash, so it's intended to be an
                          * IP address with mask
@@ -173,8 +183,15 @@ insert_acl (char *location, acl_access_t access_type, vector_t *access_list)
 
                         acl.type = ACL_NUMERIC;
 
+                        /* Check if the IP address before the netmask is
+                         * an IPv6 address */
+                        if (inet_pton(AF_INET6, location, dst) > 0)
+                                v6 = 1;
+                        else
+                                v6 = 0;
+
                         if (fill_netmask_array
-                            (p + 1, &(acl.address.ip.mask[0]), IPV6_LEN)
+                            (p + 1, v6, &(acl.address.ip.mask[0]), IPV6_LEN)
                             < 0)
                                 return -1;
