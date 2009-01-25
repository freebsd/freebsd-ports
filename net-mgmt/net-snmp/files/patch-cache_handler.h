--- include/net-snmp/agent/cache_handler.h.orig	2009-01-25 22:37:09.000000000 +0900
+++ include/net-snmp/agent/cache_handler.h	2009-01-25 22:38:07.000000000 +0900
@@ -85,6 +85,8 @@
     netsnmp_cache_create(int timeout, NetsnmpCacheLoad * load_hook,
                          NetsnmpCacheFree * free_hook,
                          oid * rootoid, int rootoid_len);
+    int netsnmp_cache_free(netsnmp_cache *cache);
+
     netsnmp_mib_handler *
     netsnmp_cache_handler_get(netsnmp_cache* cache);
 
