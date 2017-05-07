--- shared/file-util.c.orig	2015-10-24 00:02:43 UTC
+++ shared/file-util.c
@@ -44,13 +44,13 @@ current_time_str(char *str, size_t len, 
 	t = time(NULL);
 	t_local = localtime(&t);
 	if (!t_local) {
-		errno = ETIME;
+		errno = ETIMEDOUT;
 		return -1;
 	}
 
 	ret = strftime(str, len, fmt, t_local);
 	if (ret == 0) {
-		errno = ETIME;
+		errno = ETIMEDOUT;
 		return -1;
 	}
 
