--- src/protocols/oscar/oscar.c.orig	Tue Jun  1 18:12:11 2004
+++ src/protocols/oscar/oscar.c	Tue Jun  1 18:12:58 2004
@@ -3127,7 +3127,7 @@
 	 * Note: There *may* be some clients which send messages as HTML formatted -
 	 *       they need to be special-cased somehow.
 	 */
-	if (isdigit(gaim_account_get_username(account)[0]) && isdigit(userinfo->sn[0])) {
+	if (isdigit(gaim_account_get_username(account)[0]) && isdigit(userinfo->sn[0]) && g_strncasecmp(tmp, "<HTML>", 6)) {
 		/* being recevied by ICQ from ICQ - escape HTML so it is displayed as sent */
 		gchar *tmp2 = gaim_escape_html(tmp);
 		g_free(tmp);
