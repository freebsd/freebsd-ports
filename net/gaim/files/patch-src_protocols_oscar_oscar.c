--- src/protocols/oscar/oscar.c.orig	Sun Aug  8 01:32:27 2004
+++ src/protocols/oscar/oscar.c	Sun Aug  8 01:40:47 2004
@@ -3136,7 +3136,7 @@
 	 * Note: There *may* be some clients which send messages as HTML formatted -
 	 *       they need to be special-cased somehow.
 	 */
-	if (isdigit(gaim_account_get_username(account)[0]) && isdigit(userinfo->sn[0])) {
+	if (isdigit(gaim_account_get_username(account)[0]) && isdigit(userinfo->sn[0]) && g_strncasecmp(tmp, "<HTML>", 6)) {
 		/* being recevied by ICQ from ICQ - escape HTML so it is displayed as sent */
 		gchar *tmp2 = gaim_escape_html(tmp);
 		g_free(tmp);
@@ -3473,6 +3473,9 @@
 	gchar **msg1, **msg2;
 	GError *err = NULL;
 	int i, numtoks;
+#ifdef HAVE_TM_GMTOFF
+	struct tm tm;
+#endif
 
 	if (!args->type || !args->msg || !args->uin)
 		return 1;
@@ -3507,8 +3510,15 @@
 
 				if (t) { /* This is an offline message */
 					/* The timestamp is UTC-ish, so we need to get the offset */
+#ifdef HAVE_TM_GMTOFF
+					localtime_r(&t, &tm);
+					t += tm.tm_gmtoff;
+#else
+#ifdef HAVE_TIMEZONE
 					tzset();
 					t -= timezone;
+#endif
+#endif
 					serv_got_im(gc, uin, tmp, 0, t);
 				} else { /* This is a message from MacICQ/Miranda */
 					serv_got_im(gc, uin, tmp, 0, time(NULL));
