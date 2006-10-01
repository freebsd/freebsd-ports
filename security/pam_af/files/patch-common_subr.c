--- common/subr.c.orig	Sun Oct  1 18:13:16 2006
+++ common/subr.c	Sun Oct  1 18:14:09 2006
@@ -322,7 +322,7 @@
 	const char	*db;
 	char		*host;
 {
-	datum			key, data;
+	datum			key, data = {NULL, 0};
 	struct			myaddrinfo *res0, *res;
 	static hostrule_t	hstent;
 	int			found = 0;
