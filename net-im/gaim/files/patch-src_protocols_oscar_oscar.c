--- src/protocols/oscar/oscar.c.orig	Wed Aug 25 21:29:00 2004
+++ src/protocols/oscar/oscar.c	Thu Aug 26 21:55:32 2004
@@ -3247,7 +3247,7 @@
 	 * Note: There *may* be some clients which send messages as HTML formatted -
 	 *       they need to be special-cased somehow.
 	 */
-	if (isdigit(gaim_account_get_username(account)[0]) && isdigit(userinfo->sn[0])) {
+	if (isdigit(gaim_account_get_username(account)[0]) && isdigit(userinfo->sn[0]) && g_strncasecmp(tmp, "<HTML>", 6)) {
 		/* being recevied by ICQ from ICQ - escape HTML so it is displayed as sent */
 		gchar *tmp2 = gaim_escape_html(tmp);
 		g_free(tmp);
