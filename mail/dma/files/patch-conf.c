--- conf.c.orig	2016-02-07 12:41:49 UTC
+++ conf.c
@@ -121,7 +121,7 @@ parse_authfile(const char *path)
 
 		au = calloc(1, sizeof(*au));
 		if (au == NULL)
-			errlog(EX_OSERR, NULL);
+			errlog(EX_OSERR, "calloc failed");
 
 		data = strdup(line);
 		au->login = strsep(&data, "|");
