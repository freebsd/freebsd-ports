--- snmplib/mib.c.orig	Sun Nov  2 12:50:39 2003
+++ snmplib/mib.c	Sat Jan  3 03:08:38 2004
@@ -167,6 +167,14 @@
     {NULL, 0}                   /* end of list */
 };
 
+enum inet_address_type {
+    IPV4 = 1,
+    IPV6 = 2,
+    IPV4Z = 3,
+    IPV6Z = 4,
+    DNS = 16
+};
+
 
 /**
  * @internal
@@ -3734,6 +3742,80 @@
     return SNMPERR_SUCCESS;
 }
 
+/*
+ * dump_realloc_oid_to_inetaddress:
+ *   return 1 for success,
+ *   return 0 for failure,
+ *   return 2 for not handled
+ */
+
+int 
+dump_realloc_oid_to_inetaddress(const int addr_type, const oid * objid, size_t objidlen, 
+                                u_char ** buf, size_t * buf_len,
+                                size_t * out_len, int allow_realloc, 
+                                char quotechar)
+{
+    if (buf) {
+        int             i, len;
+        char            intbuf[64], * p;
+        u_int32_t       zone;
+
+        memset(intbuf, 0, 64);
+
+        p = intbuf;
+        *p = quotechar;
+        p++;
+        switch (addr_type) {
+            case IPV4:
+            case IPV4Z:
+                if ((addr_type == IPV4 && objidlen != 4) ||
+                    (addr_type == IPV4Z && objidlen != 8))
+                    return 2;
+
+                len = sprintf(p, "%lu.%lu.%lu.%lu", objid[0], objid[1], objid[2], objid[3]);
+                p += len;
+                if (addr_type == IPV4Z) {
+                    zone = ntohl(*((u_int32_t *) objid[4]));
+                    len = sprintf(p, "\%%lu", zone);
+                    p += len;
+                }
+
+                break;
+
+            case IPV6:
+            case IPV6Z:
+                if ((addr_type == IPV6 && objidlen != 16) ||
+                    (addr_type == IPV6Z && objidlen != 20))
+                    return 2;
+
+                len = 0;
+                for (i = 0; i < 16; i ++) {
+                    len += snprintf(p, 4, "%02x:", objid[i]);
+                    p += 3;
+                }
+                p-- ; /* do not include the last ':' */
+
+                if (addr_type == IPV6Z) {
+                    zone = ntohl(*((u_int32_t *) objid[4]));
+                    len = sprintf(p, "\%%lu", zone);
+                    p += len;
+                }
+
+                break;
+
+            case DNS:
+            default: 
+                /* DNS can just be handled by dump_realloc_oid_to_string() */
+                return 2;
+        }
+
+        *p = quotechar;
+        return snmp_strcat(buf, buf_len, out_len, allow_realloc, 
+                                               (const u_char *) intbuf);
+    }
+    return 1;
+}
+
 int
 dump_realloc_oid_to_string(const oid * objid, size_t objidlen,
                            u_char ** buf, size_t * buf_len,
@@ -4043,7 +4125,36 @@
                     }
                 } else {
                     if (!*buf_overflow) {
-                        if (!dump_realloc_oid_to_string
+                        struct tree * next_peer;
+                        int normal_handling = 1;
+
+                        if (tp->next_peer) {
+                            next_peer = tp->next_peer;
+                        }
+
+                        /* Try handling the InetAddress in the OID, in case of failure,
+                         * use the normal_handling. 
+                         */
+                        if (tp->next_peer &&
+                            strcmp(get_tc_descriptor(tp->tc_index), "InetAddress") == 0 &&
+                            strcmp(get_tc_descriptor(next_peer->tc_index), 
+                                    "InetAddressType") == 0 ) {
+
+                            int ret;
+                            int addr_type = *(objid - 1);
+
+                            ret = dump_realloc_oid_to_inetaddress(addr_type, 
+                                        objid + 1, numids - 1, buf, buf_len, out_len,
+                                        allow_realloc, '"');
+                            if (ret != 2) {
+                                normal_handling = 0;
+                                if (ret == 0) {
+                                    *buf_overflow = 1;
+                                }
+
+                            }
+                        } 
+                        if (normal_handling && !dump_realloc_oid_to_string
                             (objid + 1, numids - 1, buf, buf_len, out_len,
                              allow_realloc, '"')) {
                             *buf_overflow = 1;
