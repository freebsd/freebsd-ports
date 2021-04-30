--- src/bin/lttng-sessiond/consumer.c.orig	2017-01-09 19:26:28 UTC
+++ src/bin/lttng-sessiond/consumer.c
@@ -17,6 +17,7 @@
 
 #define _LGPL_SOURCE
 #include <assert.h>
+#include <limits.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -635,7 +636,7 @@ int consumer_set_network_uri(struct consumer_output *o
 {
 	int ret;
 	char tmp_path[PATH_MAX];
-	char hostname[HOST_NAME_MAX];
+	char hostname[_POSIX_HOST_NAME_MAX];
 	struct lttng_uri *dst_uri = NULL;
 
 	/* Code flow error safety net. */
