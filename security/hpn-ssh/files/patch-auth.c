--- auth.c.orig	Tue Mar  5 02:42:43 2002
+++ auth.c	Sun Mar 17 20:53:15 2002
@@ -193,6 +193,17 @@
 	}
 #endif /* WITH_AIXAUTHENTICATE */
 
+#ifdef TEST__FreeBSD__
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
