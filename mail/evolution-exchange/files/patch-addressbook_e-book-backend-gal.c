--- addressbook/e-book-backend-gal.c.orig	Fri Jun  3 09:32:12 2005
+++ addressbook/e-book-backend-gal.c	Wed Sep  7 05:24:12 2005
@@ -413,12 +413,13 @@
 	   the op after either */
 	msg_type = ldap_msgtype (res);
 	if (msg_type == LDAP_RES_SEARCH_ENTRY) {
-		g_mutex_lock (bl->priv->ldap_lock);
-		LDAPMessage *e = ldap_first_entry(bl->priv->ldap, res);
-		g_mutex_unlock (bl->priv->ldap_lock);
-
+		LDAPMessage *e;
 		EContact *contact;
 		char *vcard;
+
+		g_mutex_lock (bl->priv->ldap_lock);
+		e = ldap_first_entry(bl->priv->ldap, res);
+		g_mutex_unlock (bl->priv->ldap_lock);
 
 		if (!e) {
 			g_warning ("uh, this shouldn't happen");
