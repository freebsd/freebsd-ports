--- auth.c.orig	Mon Mar 19 23:15:57 2001
+++ auth.c	Fri Jun  1 07:59:43 2001
@@ -158,6 +158,17 @@
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
