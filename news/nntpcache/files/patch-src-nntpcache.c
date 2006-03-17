--- src/nntpcache.c.orig	Fri Mar 17 07:53:45 2006
+++ src/nntpcache.c	Fri Mar 17 07:53:51 2006
@@ -810,7 +810,7 @@
 				loge (("missing password in %s:%d: %s", file, n, buf));
 				continue;
 			}
-			if ((hostname = strrchr(password-2, '@')) != NULL) {
+			if ((hostname = strrchr(password, '@')) != NULL) {
 				*(hostname++) = '\0';
 				username = host;
 				list->user = Sstrdup (username);
