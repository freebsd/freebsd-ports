--- auth.c.orig	Wed Sep  6 21:36:43 2006
+++ auth.c	Sat Sep 30 10:38:04 2006
@@ -500,7 +501,7 @@
 	if (!allowed_user(pw))
 		return (NULL);
 #ifdef HAVE_LOGIN_CAP
-	if ((lc = login_getclass(pw->pw_class)) == NULL) {
+	if ((lc = login_getpwclass(pw)) == NULL) {
 		debug("unable to get login class: %s", user);
 		return (NULL);
 	}
