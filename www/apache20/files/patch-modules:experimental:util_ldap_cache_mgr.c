--- modules/experimental/util_ldap_cache_mgr.c       Thu Sep 23 18:55:37 2004
+++ modules/experimental/util_ldap_cache_mgr.c    Wed Nov  3 06:17:59 2004
@@ -173,7 +173,7 @@
 void util_ald_cache_purge(util_ald_cache_t *cache)
 {
     unsigned long i;
-    util_cache_node_t *p, *q;
+    util_cache_node_t *p, *q, **pp;
     apr_time_t t;

     if (!cache)
@@ -184,7 +184,8 @@
     cache->numpurges++;

     for (i=0; i < cache->size; ++i) {
-        p = cache->nodes[i];
+        pp = cache->nodes + i;
+        p = *pp;
         while (p != NULL) {
             if (p->add_time < cache->marktime) {
                 q = p->next;
@@ -192,11 +193,12 @@
                 util_ald_free(cache, p);
                 cache->numentries--;
                 cache->npurged++;
-                p = q;
+                p = *pp = q;
             }
             else {
-                p = p->next;
-            }
+
+                 pp = &(p->next);
+                 p = *pp;            }
         }
     }

@@ -686,7 +688,9 @@
                 default:
                     break;
             }
-
+         }
+         else {
+             buf = "";
         }
     }
     else {
