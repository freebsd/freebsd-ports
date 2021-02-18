--- auth-bozo.c.orig	2021-02-14 09:39:00 UTC
+++ auth-bozo.c
@@ -106,9 +106,9 @@ bozo_auth_check(bozo_httpreq_t *request, const char *f
 				break;
 			fclose(fp);
 
-#ifndef NO_BLOCKLIST_SUPPORT
-			pfilter_notify(BLOCKLIST_AUTH_OK, 200);
-#endif /* !NO_BLOCKLIST_SUPPORT */
+#ifndef NO_BLACKLIST_SUPPORT
+			pfilter_notify(BLACKLIST_AUTH_OK, 200);
+#endif /* !NO_BLACKLIST_SUPPORT */
 
 			return 0;
 		}
