--- conf.c.orig	2026-08-30 20:07:40 UTC
+++ conf.c
@@ -123,7 +123,7 @@ parse_authfile(const char *path)
 
 		au = calloc(1, sizeof(*au));
 		if (au == NULL)
-			errlog(EX_OSERR, NULL);
+			errlog(EX_OSERR, "calloc failed");
 
 		data = strdup(line);
 		au->login = strsep(&data, "|");
