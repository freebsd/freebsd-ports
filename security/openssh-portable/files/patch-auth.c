r100838 | fanf | 2002-07-28 19:36:24 -0500 (Sun, 28 Jul 2002) | 7 lines
Changed paths:
   M /head/crypto/openssh/auth.c

Use login_getpwclass() instead of login_getclass() so that the root
vs. default login class distinction is made correctly.

PR:             37416

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
