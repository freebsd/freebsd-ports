--- agent/helpers/cache_handler.c.orig	2009-01-25 22:40:13.000000000 +0900
+++ agent/helpers/cache_handler.c	2009-01-25 22:44:30.000000000 +0900
@@ -173,6 +173,31 @@
     return cache;
 }
 
+/** frees a cache
+ */
+int
+netsnmp_cache_free(netsnmp_cache *cache)
+{
+    netsnmp_cache  *pos;
+
+    if (NULL == cache)
+        return SNMPERR_SUCCESS;
+
+    for (pos = cache_head; pos; pos = pos->next) {
+        if (pos == cache) {
+            snmp_log(LOG_WARNING, "not freeing cache (still in list)\n");
+            return SNMP_ERR_GENERR;
+        }
+    }
+
+    if (cache->rootoid)
+        free(cache->rootoid);
+
+    free(cache);
+
+    return SNMPERR_SUCCESS;
+}
+
 /** callback function to call cache load function */
 static void
 _timer_reload(unsigned int regNo, void *clientargs)
