--- mod_cfg_ldap.c.orig	Mon Nov 17 15:06:22 2003
+++ mod_cfg_ldap.c	Mon Nov 17 15:08:22 2003
@@ -85,11 +85,11 @@
 cfg_ldap_init_ldap (apr_pool_t * p, server_rec * s)
 {
   cfg_ldap_cfg *cfg;
+  int rc;
   cfg =
     (cfg_ldap_cfg *) ap_get_module_config (s->module_config,
 					   &cfg_ldap_module);
 
-  int rc;
   ld = ldap_init (cfg->hostname, LDAP_PORT);
   rc = ldap_simple_bind_s (ld, cfg->username, cfg->password);
 
@@ -154,22 +154,30 @@
 cfg_ldap_read_vhost_from_ldap (apr_pool_t * p, server_rec * s, char *hostname)
 {
   cfg_ldap_cfg *cfg;
+  cfg_ldap_vhost *vhost;
+  char *filter;
+  int rc,count;
+  LDAPMessage *res;
+  LDAPMessage *entry;
+  char *attr;
+  BerElement *ber;
+  char **val = NULL;
+  char *vhost_name = NULL;
+  char *vhost_admin = NULL;
+  char *vhost_docroot = NULL;
+
   cfg =
     (cfg_ldap_cfg *) ap_get_module_config (s->module_config,
 					   &cfg_ldap_module);
 
-  cfg_ldap_vhost *vhost;
   vhost = (cfg_ldap_vhost *) apr_pcalloc (p, sizeof (cfg_ldap_vhost));
   vhost->timestamp = apr_time_now ();
   vhost->name = CFG_LDAP_NO_SUCH_VHOST;
 
-  char *filter;
   filter =
     apr_pstrcat (p, "(|(apacheServerName=", hostname, ")(apacheServerAlias=",
 		 hostname, "))", NULL);
 
-  int rc;
-  LDAPMessage *res;
   rc = ldap_search_s (ld, cfg->basedn, LDAP_SCOPE_SUBTREE, filter,
 		      (char **) &attrs, 0, &res);
 
@@ -185,10 +193,9 @@
       return vhost;
     }
 
-  LDAPMessage *entry;
   entry = ldap_first_entry (ld, res);
 
-  int count = ldap_count_entries (ld, res);
+  count = ldap_count_entries (ld, res);
   if (count == 0)
     {
       return vhost;
@@ -199,13 +206,6 @@
 		    "cfg_ldap: more than one entry for %s", hostname);
       return vhost;
     }
-
-  char *attr;
-  BerElement *ber;
-  char **val = NULL;
-  char *vhost_name = NULL;
-  char *vhost_admin = NULL;
-  char *vhost_docroot = NULL;
 
   for (attr = ldap_first_attribute (ld, entry, &ber);
        attr != NULL; attr = ldap_next_attribute (ld, entry, ber))
