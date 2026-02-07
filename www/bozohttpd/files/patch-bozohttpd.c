--- bozohttpd.c.orig	2024-02-04 05:55:04 UTC
+++ bozohttpd.c
@@ -2203,22 +2203,22 @@ http_errors_long(int code)
 	return (help);
 }
 
-#ifndef NO_BLOCKLIST_SUPPORT
-static struct blocklist *blstate;
+#ifndef NO_BLACKLIST_SUPPORT
+static struct blacklist *blstate;
 
 void
 pfilter_notify(const int what, const int code)
 {
 
 	if (blstate == NULL)
-		blstate = blocklist_open();
+		blstate = blacklist_open();
 
 	if (blstate == NULL)
 		return;
 
-	(void)blocklist_r(blstate, what, 0, http_errors_short(code));
+	(void)blacklist_r(blstate, what, 0, http_errors_short(code));
 }
-#endif /* !NO_BLOCKLIST_SUPPORT */
+#endif /* !NO_BLACKLIST_SUPPORT */
 
 /* the follow functions and variables are used in handling HTTP errors */
 int
@@ -2323,18 +2323,18 @@ bozo_http_error(bozohttpd_t *httpd, int code, bozo_htt
 		bozo_printf(httpd, "%s", httpd->errorbuf);
 	bozo_flush(httpd, stdout);
 
-#ifndef NO_BLOCKLIST_SUPPORT
+#ifndef NO_BLACKLIST_SUPPORT
 	switch(code) {
 
 	case 401:
-		pfilter_notify(BLOCKLIST_AUTH_FAIL, code);
+		pfilter_notify(BLACKLIST_AUTH_FAIL, code);
 		break;
 
 	case 403:
-		pfilter_notify(BLOCKLIST_ABUSIVE_BEHAVIOR, code);
+		pfilter_notify(BLACKLIST_ABUSIVE_BEHAVIOR, code);
 		break;
 	}
-#endif /* !NO_BLOCKLIST_SUPPORT */
+#endif /* !NO_BLACKLIST_SUPPORT */
 
 	return code;
 }
