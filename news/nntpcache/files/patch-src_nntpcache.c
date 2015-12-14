--- src/nntpcache.c.orig	2004-04-11 11:43:56 UTC
+++ src/nntpcache.c
@@ -810,7 +810,7 @@ static bool load_servers(char *file)
 				loge (("missing password in %s:%d: %s", file, n, buf));
 				continue;
 			}
-			if ((hostname = strrchr(password-2, '@')) != NULL) {
+			if ((hostname = strrchr(password, '@')) != NULL) {
 				*(hostname++) = '\0';
 				username = host;
 				list->user = Sstrdup (username);
