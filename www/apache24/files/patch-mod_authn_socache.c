mod_authn_socache.c: fix creation of default socache_instance.

In pre_config, default socache_provider is created, but socache_instance
initialization is missing. This leads to crash on startup if default
socache_provider is used (AuthnCacheSOCache is not called) and
AuthnCacheEnable or AuthnCacheProvideFor is used.


Optained from: http://svn.apache.org/viewvc?view=revision&revision=1576233
======================================================================================
--- ./modules/aaa/mod_authn_socache.c	2014/03/11 08:51:11	1576232
+++ ./modules/aaa/mod_authn_socache.c	2014/03/11 08:52:54	1576233
@@ -86,6 +86,7 @@
 {
     apr_status_t rv;
     static struct ap_socache_hints authn_cache_hints = {64, 32, 60000000};
+    const char *errmsg;
 
     if (!configured) {
         return OK;    /* don't waste the overhead of creating mutex & cache */
@@ -98,6 +99,20 @@
         return 500; /* An HTTP status would be a misnomer! */
     }
 
+    /* We have socache_provider, but do not have socache_instance. This should
+     * happen only when using "default" socache_provider, so create default
+     * socache_instance in this case. */
+    if (socache_instance == NULL) {
+        errmsg = socache_provider->create(&socache_instance, NULL,
+                                          ptmp, pconf);
+        if (errmsg) {
+            ap_log_perror(APLOG_MARK, APLOG_CRIT, rv, plog, APLOGNO(02612)
+                        "failed to create mod_socache_shmcb socache "
+                        "instance: %s", errmsg);
+            return 500;
+        }
+    }
+
     rv = ap_global_mutex_create(&authn_cache_mutex, NULL,
                                 authn_cache_id, NULL, s, pconf, 0);
     if (rv != APR_SUCCESS) {
