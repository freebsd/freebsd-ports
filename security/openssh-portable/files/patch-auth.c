--- auth.c.orig	2010-08-12 11:33:01.000000000 -0600
+++ auth.c	2010-09-14 16:14:12.000000000 -0600
@@ -594,7 +594,7 @@
 	if (!allowed_user(pw))
 		return (NULL);
 #ifdef HAVE_LOGIN_CAP
-	if ((lc = login_getclass(pw->pw_class)) == NULL) {
+	if ((lc = login_getpwclass(pw)) == NULL) {
 		debug("unable to get login class: %s", user);
 		return (NULL);
 	}
