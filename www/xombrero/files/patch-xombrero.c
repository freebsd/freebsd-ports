--- ./xombrero.c.orig	2012-07-25 17:37:55.000000000 -0400
+++ ./xombrero.c	2012-07-31 08:13:02.000000000 -0400
@@ -1423,7 +1423,7 @@
 {
 	struct passwd		*pwd;
 	int			i;
-	char			user[LOGIN_NAME_MAX];
+	char			user[sysconf(_SC_LOGIN_NAME_MAX)];
 	const char		*sc = s;
 
 	if (path == NULL || s == NULL)
