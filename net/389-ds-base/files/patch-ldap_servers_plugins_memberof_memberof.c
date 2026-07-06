--- ldap/servers/plugins/memberof/memberof.c.orig	2026-06-28 10:10:14 UTC
+++ ldap/servers/plugins/memberof/memberof.c
@@ -1873,7 +1873,7 @@ memberof_call_foreach_dn(Slapi_PBlock *pb __attribute_
         ht_grp = ancestors_cache_lookup(config, (const void *)ndn);
         if (ht_grp) {
 #if MEMBEROF_CACHE_DEBUG
-            slapi_log_err(SLAPI_LOG_PLUGIN, MEMBEROF_PLUGIN_SUBSYSTEM, "memberof_call_foreach_dn: Ancestors of %s already cached (%lx)\n", ndn, (ulong) ht_grp);
+            slapi_log_err(SLAPI_LOG_PLUGIN, MEMBEROF_PLUGIN_SUBSYSTEM, "memberof_call_foreach_dn: Ancestors of %s already cached (%lx)\n", ndn, (unsigned long) ht_grp);
 #endif
             add_ancestors_cbdata(ht_grp, callback_data);
             *cached = 1;
