--- src/bin/lttng-sessiond/consumer.c.orig	2016-11-29 22:48:37 UTC
+++ src/bin/lttng-sessiond/consumer.c 
@@ -635,6 +635,9 @@ int consumer_set_network_uri(struct cons
 {
 	int ret;
 	char tmp_path[PATH_MAX];
+#if defined(__FreeBSD__)
+	const size_t HOST_NAME_MAX = sysconf(_SC_HOST_NAME_MAX);
+#endif
 	char hostname[HOST_NAME_MAX];
 	struct lttng_uri *dst_uri = NULL;
 
