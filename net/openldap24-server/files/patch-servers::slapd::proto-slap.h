--- servers/slapd/proto-slap.h	Mon Oct 13 03:57:02 2003
+++ servers/slapd/proto-slap.h	Sun Oct 19 15:33:56 2003
@@ -1175,16 +1175,10 @@
  * syncrepl.c
  */
 
-LDAP_SLAPD_V( const struct berval ) slap_syncrepl_bvc;
-LDAP_SLAPD_V( const struct berval ) slap_syncrepl_cn_bvc;
-
 LDAP_SLAPD_V (struct runqueue_s) syncrepl_rq;
 
-LDAP_SLAPD_F (void) init_syncrepl LDAP_P(());
+LDAP_SLAPD_F (void) init_syncrepl LDAP_P((syncinfo_t *));
 LDAP_SLAPD_F (void*) do_syncrepl LDAP_P((void *, void *));
-LDAP_SLAPD_F (int) ldap_sync_search LDAP_P((
-					syncinfo_t *, LDAP *, LDAPControl **,
-					LDAPControl **, int *));
 LDAP_SLAPD_F (Entry*) syncrepl_message_to_entry LDAP_P((
 					syncinfo_t *, LDAP *, Operation *, LDAPMessage *,
 					Modifications **, int*, struct berval *, struct berval * ));
