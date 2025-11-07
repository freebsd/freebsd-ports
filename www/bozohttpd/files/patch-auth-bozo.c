--- auth-bozo.c.orig	2024-02-04 05:55:04 UTC
+++ auth-bozo.c
@@ -111,9 +111,9 @@ bozo_auth_check(bozo_httpreq_t *request, const char *f
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
