--- misc.c.orig	Thu Apr 12 22:09:37 2001
+++ misc.c	Sat May 26 15:39:25 2001
@@ -111,6 +111,10 @@
 	copy->pw_class = xstrdup(pw->pw_class);
 	copy->pw_dir = xstrdup(pw->pw_dir);
 	copy->pw_shell = xstrdup(pw->pw_shell);
+#ifdef __FreeBSD__
+	copy->pw_expire = pw->pw_expire;
+	copy->pw_change = pw->pw_change;
+#endif /* __FreeBSD__ */
 	return copy;
 }
 
