--- agent/seahorse-agent-cache.c.orig	2009-08-01 15:25:55.000000000 -0400
+++ agent/seahorse-agent-cache.c	2009-08-01 15:23:38.000000000 -0400
@@ -237,6 +237,7 @@ seahorse_agent_cache_init ()
         g_cache =
             g_hash_table_new_full (g_str_hash, g_str_equal, NULL, destroy_cache_item);
 
+	gpgme_check_version (NULL);
         err = gpgme_engine_check_version (proto);
         g_return_if_fail (GPG_IS_OK (err));
         
