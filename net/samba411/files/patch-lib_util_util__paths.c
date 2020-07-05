--- lib/util/util_paths.c.orig		2020-07-04 02:14:14 UTC
+++ lib/util/util_paths.c
@@ -68,10 +68,10 @@ static char *get_user_home_dir(TALLOC_CTX *mem_ctx)
 {
 	struct passwd pwd = {0};
 	struct passwd *pwdbuf = NULL;
-	char buf[NSS_BUFLEN_PASSWD] = {0};
+	char buf[1024] = {0};
 	int rc;
 
-	rc = getpwuid_r(getuid(), &pwd, buf, NSS_BUFLEN_PASSWD, &pwdbuf);
+	rc = getpwuid_r(getuid(), &pwd, buf, 1024, &pwdbuf);
 	if (rc != 0 || pwdbuf == NULL ) {
 		int len_written;
 		const char *szPath = getenv("HOME");
