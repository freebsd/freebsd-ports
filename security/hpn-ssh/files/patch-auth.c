--- auth.c.orig	Tue Sep  2 23:32:46 2003
+++ auth.c	Tue Sep 16 20:05:44 2003
@@ -259,6 +259,17 @@
 	}
 #endif /* WITH_AIXAUTHENTICATE */
 
+#ifdef __FreeBSD__
+	/* Fail if the account's expiration time has passed. */
+	if (pw->pw_expire != 0) {
+		struct timeval tv;
+
+		(void)gettimeofday(&tv, NULL);
+		if (tv.tv_sec >= pw->pw_expire)
+			return 0;
+	}
+#endif /* __FreeBSD__ */
+
 	/* We found no reason not to let this user try to log on... */
 	return 1;
 }
@@ -531,7 +542,7 @@
 	if (!allowed_user(pw))
 		return (NULL);
 #ifdef HAVE_LOGIN_CAP
-	if ((lc = login_getclass(pw->pw_class)) == NULL) {
+	if ((lc = login_getpwclass(pw)) == NULL) {
 		debug("unable to get login class: %s", user);
 		return (NULL);
 	}
