Index: modules/experimental/util_ldap_cache_mgr.c
===================================================================
RCS file: /home/cvs/httpd-2.0/modules/experimental/Attic/util_ldap_cache_mgr.c,v
retrieving revision 1.3.2.13
diff -u -r1.3.2.13 util_ldap_cache_mgr.c
--- modules/experimental/util_ldap_cache_mgr.c	23 Sep 2004 16:55:37 -0000	1.3.2.13
+++ modules/experimental/util_ldap_cache_mgr.c	24 Sep 2004 16:40:23 -0000
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
@@ -192,10 +193,11 @@
                 util_ald_free(cache, p);
                 cache->numentries--;
                 cache->npurged++;
-                p = q;
+                p = *pp = q;
             }
             else {
-                p = p->next;
+                pp = &(p->next);
+                p = *pp;
             }
         }
     }
@@ -687,6 +689,9 @@
                     break;
             }
 
+        }
+        else {
+            buf = "";
         }
     }
     else {
