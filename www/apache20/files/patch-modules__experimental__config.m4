--- modules/experimental/config.m4.orig	2010-05-07 00:41:44.796911069 -0400
+++ modules/experimental/config.m4	2010-05-07 00:41:27.000000000 -0400
@@ -33,7 +33,7 @@
 ldap_objects="util_ldap.lo util_ldap_cache.lo util_ldap_cache_mgr.lo"
 APACHE_MODULE(ldap, LDAP caching and connection pooling services, $ldap_objects, , no)
 
-auth_ldap_objects="mod_auth_ldap.lo"
+auth_ldap_objects="mod_auth_ldap.lo $ldap_objects"
 APACHE_MODULE(auth_ldap, LDAP based authentication, $auth_ldap_objects, , no)
 
 APACHE_MODPATH_FINISH
