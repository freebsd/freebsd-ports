--- auth.c.orig	Thu Aug 12 14:40:25 2004
+++ auth.c	Mon Sep 20 05:04:48 2004
@@ -208,6 +208,17 @@
 		return 0;
 #endif
 
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
@@ -472,7 +483,7 @@
 	if (!allowed_user(pw))
 		return (NULL);
 #ifdef HAVE_LOGIN_CAP
-	if ((lc = login_getclass(pw->pw_class)) == NULL) {
+	if ((lc = login_getpwclass(pw)) == NULL) {
 		debug("unable to get login class: %s", user);
 		return (NULL);
 	}
