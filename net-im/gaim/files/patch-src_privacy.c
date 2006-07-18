RCS file: /cvsroot/gaim/gaim/src/privacy.c,v
retrieving revision 1.16
retrieving revision 1.18
diff -u -r1.16 -r1.18
--- src/privacy.c	2005/07/17 23:36:33	1.16
+++ src/privacy.c	2006/02/07 02:49:56	1.18
@@ -85,8 +85,8 @@
 	if (l == NULL)
 		return FALSE;
 
-	account->permit = g_slist_remove(account->permit, l->data);
 	g_free(l->data);
+	account->permit = g_slist_delete_link(account->permit, l);
 
 	if (!local_only && gaim_account_is_connected(account))
 		serv_rem_permit(gaim_account_get_connection(account), who);
@@ -156,15 +156,16 @@
 	if (l == NULL)
 		return FALSE;
 
-	account->deny = g_slist_remove(account->deny, l->data);
-	g_free(l->data);
+	name = l->data;
+	account->deny = g_slist_delete_link(account->deny, l);
 
 	if (!local_only && gaim_account_is_connected(account))
-		serv_rem_deny(gaim_account_get_connection(account), who);
+		serv_rem_deny(gaim_account_get_connection(account), name);
 
 	if (privacy_ops != NULL && privacy_ops->deny_removed != NULL)
-		privacy_ops->deny_removed(account, who);
+		privacy_ops->deny_removed(account, name);
 
+	g_free(name);
 	gaim_blist_schedule_save();
 
 	return TRUE;
