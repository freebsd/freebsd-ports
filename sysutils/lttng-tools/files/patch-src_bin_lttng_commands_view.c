--- src/bin/lttng/commands/view.c.orig	2016-11-29 22:48:37 UTC
+++ src/bin/lttng/commands/view.c
@@ -269,6 +269,9 @@ static char *build_live_path(char *sessi
 {
 	int ret;
 	char *path = NULL;
+#if defined(__FreeBSD__)
+	const size_t HOST_NAME_MAX = sysconf(_SC_HOST_NAME_MAX);
+#endif
 	char hostname[HOST_NAME_MAX];
 
 	ret = gethostname(hostname, sizeof(hostname));
